import java.util.Arrays;
import java.util.Scanner;

public class isObese {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String[] genders = {"Male", "Female"};
        System.out.print("Enter (Male / Female): ");
        String gender = scanner.nextLine();
        int genderCode;
        if (Arrays.asList(genders).contains(gender)) {
            genderCode = gender.contentEquals(genders[0]) ? 0 : 1;
        } else {
            return;
        }

        System.out.print("Enter your body weight in kilograms: ");
        float bodyweight = scanner.nextFloat();
        System.out.print("Enter your height in meters: ");
        float height = scanner.nextFloat();

        float BMI = bodyweight / (height * height);

        if (genderCode == 0 && BMI >= 27.8 || genderCode == 1 && BMI >= 25) {
            System.out.println("You are obese. BMI = " + BMI);
        } else {
            System.out.println("You are not obese. BMI = " + BMI);
        }

    }
}
