import java.sql.*; 
public class Main { 
    public static void main(String[] args) {
        String url = "jdbc:oracle:thin:@orcl:1521:ORCL";
        String user = "g123";
        String pass = "g123";

        try (Connection conn = DriverManager.getConnection(url, user, pass)) {
            System.out.println("Database Connected Successfully!");

            Statement st = conn.createStatement();
            ResultSet rs = st.executeQuery("SELECT * FROM actors");

            while(rs.next()) {
                System.out.println("ID: " + rs.getInt("id") + " | Name: " + rs.getString("first_name"));
            }
        } catch (SQLException e) {
            System.err.println(" Connection Failed!");
            e.printStackTrace();
        }
    }
}
