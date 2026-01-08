import java.util.Scanner;

public class toFahrenheit {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter temperature in celsius: ");
        float tC = scanner.nextFloat();

        float tF = (tC * 9 / 5) + 32;

        System.out.println("Fahrenheit: "+ tF);
    }
}
