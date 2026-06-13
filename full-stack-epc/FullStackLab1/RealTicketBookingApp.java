import java.sql.*;
import java.util.concurrent.BlockingQueue;
import java.util.concurrent.LinkedBlockingQueue;

class TransactionException extends Exception {
    public TransactionException(String message) { super(message); }
}

// ==========================================
// TASK 1: Real JDBC Connection Pool
// ==========================================
class JDBCConnectionPool {
    private final BlockingQueue<Connection> pool = new LinkedBlockingQueue<>();
    private final String url;
    private final String user;
    private final String password;

    public JDBCConnectionPool(String url, String user, String password, int poolSize) throws SQLException {
        this.url = url;
        this.user = user;
        this.password = password;
        
        for (int i = 0; i < poolSize; i++) {
            pool.add(createNewConnection());
        }
    }

    private Connection createNewConnection() throws SQLException {
        Connection conn = DriverManager.getConnection(url, user, password);
        // Disable auto-commit for Two-Phase Commit control
        conn.setAutoCommit(false); 
        return conn;
    }

    public Connection getConnection() throws InterruptedException {
        return pool.take();
    }

    public void releaseConnection(Connection conn) {
        if (conn != null) {
            pool.offer(conn);
        }
    }
}

// ==========================================
// TASKS 2, 3, 4: Transaction & Business Logic
// ==========================================
class RealTicketBookingSystem {
    private final JDBCConnectionPool bookingPool;
    private final JDBCConnectionPool paymentPool;

    public RealTicketBookingSystem(JDBCConnectionPool bookingPool, JDBCConnectionPool paymentPool) {
        this.bookingPool = bookingPool;
        this.paymentPool = paymentPool;
    }

    public void bookTicket(int seatId, int accountId, double price, boolean forcePaymentFail) {
        System.out.println("\n>>> Initiating Booking for Seat " + seatId + "...");
        Connection bConn = null;
        Connection pConn = null;

        try {
            bConn = bookingPool.getConnection();
            pConn = paymentPool.getConnection();

            // Phase 1: Prepare
            PreparedStatement bookStmt = bConn.prepareStatement(
                "UPDATE seats SET status = 'BOOKED' WHERE id = ? AND status = 'AVAILABLE'"
            );
            bookStmt.setInt(1, seatId);
            int seatUpdated = bookStmt.executeUpdate();

            PreparedStatement payStmt = pConn.prepareStatement(
                "UPDATE accounts SET balance = balance - ? WHERE id = ? AND balance >= ?"
            );
            double chargeAmount = forcePaymentFail ? 999999.0 : price; 
            payStmt.setDouble(1, chargeAmount);
            payStmt.setInt(2, accountId);
            payStmt.setDouble(3, chargeAmount);
            int paymentUpdated = payStmt.executeUpdate();

            // Phase 2: Commit / Rollback
            if (seatUpdated == 1 && paymentUpdated == 1) {
                bConn.commit();
                pConn.commit();
                System.out.println(">>> RESULT: Ticket Booked Successfully! Databases committed.");
            } else {
                throw new TransactionException("Booking Failed – Transaction Rolled Back");
            }

        } catch (Exception e) {
            System.err.println(">>> RESULT: " + e.getMessage());
            rollbackSafely(bConn, pConn);
        } finally {
            bookingPool.releaseConnection(bConn);
            paymentPool.releaseConnection(pConn);
        }
    }

    public void cancelTicket(int seatId, int accountId, double refundAmount, boolean forceRefundFail) {
        System.out.println("\n>>> Initiating Cancellation for Seat " + seatId + "...");
        Connection bConn = null;
        Connection pConn = null;

        try {
            bConn = bookingPool.getConnection();
            pConn = paymentPool.getConnection();

            PreparedStatement cancelStmt = bConn.prepareStatement(
                "UPDATE seats SET status = 'AVAILABLE' WHERE id = ? AND status = 'BOOKED'"
            );
            cancelStmt.setInt(1, seatId);
            int seatReleased = cancelStmt.executeUpdate();

            PreparedStatement refundStmt = pConn.prepareStatement(
                "UPDATE accounts SET balance = balance + ? WHERE id = ?"
            );
            refundStmt.setDouble(1, refundAmount);
            refundStmt.setInt(2, accountId);
            
            int refundProcessed = forceRefundFail ? 0 : refundStmt.executeUpdate();

            if (seatReleased == 1 && (refundProcessed == 1 || !forceRefundFail)) {
                bConn.commit();
                pConn.commit();
                System.out.println(">>> RESULT: Ticket Cancelled and Refunded Successfully!");
            } else {
                throw new TransactionException("Cancellation Failed – Transaction Rolled Back");
            }

        } catch (Exception e) {
            System.err.println(">>> RESULT: " + e.getMessage());
            rollbackSafely(bConn, pConn);
        } finally {
            bookingPool.releaseConnection(bConn);
            paymentPool.releaseConnection(pConn);
        }
    }

    private void rollbackSafely(Connection bConn, Connection pConn) {
        try {
            if (bConn != null) bConn.rollback();
            if (pConn != null) pConn.rollback();
            System.err.println("    [System] Rollback executed successfully on both databases.");
        } catch (SQLException ex) {
            System.err.println("    [Fatal] Rollback failed: " + ex.getMessage());
        }
    }
}

// ==========================================
// Main Execution
// ==========================================
public class RealTicketBookingApp {
    
    public static void main(String[] args) {
        // Localhost MySQL mappings from Docker
        String bookingDbUrl = "jdbc:mysql://localhost:3306/bookingdb";
        String paymentDbUrl = "jdbc:mysql://localhost:3307/paymentdb";
        String user = "root";
        String pass = "root";

        try {
            System.out.println("Setting up databases...");
            setupDatabases(bookingDbUrl, paymentDbUrl, user, pass);

            JDBCConnectionPool bookingPool = new JDBCConnectionPool(bookingDbUrl, user, pass, 5);
            JDBCConnectionPool paymentPool = new JDBCConnectionPool(paymentDbUrl, user, pass, 5);

            RealTicketBookingSystem system = new RealTicketBookingSystem(bookingPool, paymentPool);

            // 1. Happy Path: Book successfully
            system.bookTicket(101, 1, 100.0, false);
            printDatabaseState(bookingPool, paymentPool);

            // 2. Failure Path: Payment fails, rollback seat booking
            system.bookTicket(102, 1, 100.0, true); 
            printDatabaseState(bookingPool, paymentPool);

            // 3. Happy Path: Cancel successfully
            system.cancelTicket(101, 1, 100.0, false);
            printDatabaseState(bookingPool, paymentPool);

        } catch (Exception e) {
            System.err.println("Application Error: " + e.getMessage());
        }
    }

    private static void setupDatabases(String bUrl, String pUrl, String user, String pass) throws SQLException {
        try (Connection bConn = DriverManager.getConnection(bUrl, user, pass);
             Connection pConn = DriverManager.getConnection(pUrl, user, pass)) {
            
            // Fresh setup for Booking DB
            bConn.createStatement().execute("DROP TABLE IF EXISTS seats");
            bConn.createStatement().execute("CREATE TABLE seats (id INT PRIMARY KEY, status VARCHAR(20))");
            bConn.createStatement().execute("INSERT INTO seats VALUES (101, 'AVAILABLE'), (102, 'AVAILABLE')");
            
            // Fresh setup for Payment DB
            pConn.createStatement().execute("DROP TABLE IF EXISTS accounts");
            pConn.createStatement().execute("CREATE TABLE accounts (id INT PRIMARY KEY, balance DOUBLE)");
            pConn.createStatement().execute("INSERT INTO accounts VALUES (1, 500.0)"); 
        }
    }

    private static void printDatabaseState(JDBCConnectionPool bPool, JDBCConnectionPool pPool) throws Exception {
        System.out.println("--- Current Database State ---");
        Connection bConn = bPool.getConnection();
        ResultSet rs1 = bConn.createStatement().executeQuery("SELECT * FROM seats");
        while (rs1.next()) System.out.println("Seat " + rs1.getInt("id") + ": " + rs1.getString("status"));
        bPool.releaseConnection(bConn);

        Connection pConn = pPool.getConnection();
        ResultSet rs2 = pConn.createStatement().executeQuery("SELECT * FROM accounts");
        while (rs2.next()) System.out.println("Account " + rs2.getInt("id") + " Balance: $" + rs2.getDouble("balance"));
        pPool.releaseConnection(pConn);
        System.out.println("------------------------------\n");
    }
}