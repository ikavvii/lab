import java.sql.*;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) throws Exception {

        Connection con = DriverManager.getConnection(
                "jdbc:postgresql://localhost:5432/postgres",
                "postgres",
                "postgres");

        Scanner sc = new Scanner(System.in);

        System.out.println("Enter username:");
        String username = sc.nextLine();

        System.out.println("Enter password:");
        String password = sc.nextLine();

        Statement stmt = con.createStatement();

        String query =
                "SELECT * FROM users WHERE username='"
                        + username +
                        "' AND password='" +
                        password + "'";

        ResultSet rs = stmt.executeQuery(query);

        if (rs.next())
            System.out.println("Login Success");
        else
            System.out.println("Login Failed");

        con.close();
    }
}