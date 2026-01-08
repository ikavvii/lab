public class Table {
    public static void main(String[] args) {
        String[][] education = {{"MCA", "2025-26", "Coimbatore"},
                {"BCA", "2022-25", "Tiruchirappalli"},
                {"HSC", "2017-19", "Tiruchirappalli"},
                {"SSLC", "2016-17", "Tiruchirappalli"}
        };

        System.out.printf("| %-5s | %-15s | %-20s | %-20s |\n", "S. No", "Qualification", "Period of Study", "Place of Study");

        for (int i = 0; i < education.length; i++) {
            System.out.printf("| %-5s | %-15s | %-20s | %-20s |\n", i+1, education[i][0], education[i][1], education[i][2]);
        }
    }
}
