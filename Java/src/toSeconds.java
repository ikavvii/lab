import java.util.Scanner;

public class toSeconds {
    static float howManySeconds(float hours) {
        return hours * 60 * 60;
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter # of hours: ");
        float hours = scanner.nextFloat();
        System.out.println("in Seconds: " + toSeconds.howManySeconds(hours));
    }
}
