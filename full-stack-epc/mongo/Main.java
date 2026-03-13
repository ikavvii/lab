import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.Statement;

public class Main {

    public static void main(String[] args) {

        try {

            // Load driver
            Class.forName("com.mongodb.jdbc.MongoDriver");

            // Replace with YOUR Atlas SQL endpoint
            String url =
                "jdbc:mongodb://atlas-sql-6997f398a5add6fb116fbd5e-zopppv.a.query.mongodb.net/test?ssl=true&authSource=admin:27017/test";

            String username = "yourAtlasUsername";
            String password = "yourAtlasPassword";

            Connection conn =
                DriverManager.getConnection(url, username, password);

            System.out.println("Connected to Atlas via JDBC");

            Statement stmt = conn.createStatement();

            ResultSet rs =
                stmt.executeQuery("SELECT * FROM  LIMIT 5");

            while (rs.next()) {

                System.out.println(rs.getString("title"));

            }

            conn.close();

        }

        catch (Exception e) {

            e.printStackTrace();

        }

    }

}