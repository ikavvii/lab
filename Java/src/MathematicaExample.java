import java.util.Scanner;
import java.util.HashSet;
import java.util.Set;

class Mathematica {
    int number;
    long result;

    Mathematica() {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter a number: ");
        if (sc.hasNextInt()) {
            number = sc.nextInt();
        }
    }

    Mathematica(int num) {
        number = num;
    }

    long fact() {
        result = 1;
        for (int i = 1; i <= number; i++) result *= i;
        return result;
    }

    boolean perfect() {
        if (number <= 1) return false;
        result = 1;
        for (int i = 2; i * i < number; i++) {
            if (number % i == 0) {
                result += i;
                // If not the square root, add the counterpart divisor
                if (i * i != number) {
                    result += number / i;
                }
            }
        }
        return result == number;
    }

    void setNumber() {
        byte min = 0;
        byte max = (byte) (Byte.MAX_VALUE - 1);
        int range = max - min + 1;
        number = (int) (Math.random() * range) + min;
        System.out.println("number: " + number);
    }

    void trigonometricMethods() {
        double rad = Math.toRadians(number);
        System.out.println("Sin: " + Math.sin(rad));
        System.out.println("Cos: " + Math.cos(rad));
        System.out.println("Tan: " + Math.tan(rad));
    }

    boolean happyNumber() {
        Set<Integer> seen = new HashSet<>();
        return isHappy(seen, number);
    }

    private boolean isHappy(Set<Integer> seen, int n) {
        if (n == 1) return true;
        if (seen.contains(n)) return false;
        seen.add(n);
        int sum = 0;
        int temp = n;
        while (temp > 0) {
            int digit = temp % 10;
            sum += (digit * digit);
            temp /= 10;
        }
        return isHappy(seen, sum);
    }
}

public class MathematicaExample {
    static void main() {
        Mathematica math = null;
        Scanner sc = new Scanner(System.in);
        while (true) {
            System.out.println("\n1. Set number (Default constructor)");
            System.out.println("2. Set number (Parameterized constructor)");
            System.out.println("3. Set number (Random)");
            System.out.println("4. Factorial");
            System.out.println("5. Is Perfect");
            System.out.println("6. Trigonometric");
            System.out.println("7. Is Happy");
            System.out.println("8. Exit");
            System.out.print("Enter choice: ");

            if (!sc.hasNextInt()) break;
            int choice = sc.nextInt();

            if (choice >= 4 && choice <= 7 && math == null) {
                System.out.println("Set the number first. (Option 1, 2 or 3)");
                continue;
            }

            switch (choice) {
                case 1:
                    math = new Mathematica();
                    break;
                case 2:
                    System.out.print("Enter number: ");
                    math = new Mathematica(sc.nextInt());
                    break;
                case 3:
                    math = new Mathematica(0);
                    math.setNumber();
                    break;
                case 4:
                    System.out.println("Factorial = " + math.fact());
                    break;
                case 5:
                    System.out.println(math.number + (math.perfect() ? " is Perfect" : " is not Perfect"));
                    break;
                case 6:
                    math.trigonometricMethods();
                    break;
                case 7:
                    System.out.println(math.number + (math.happyNumber() ? " is Happy" : " is not Happy"));
                    break;
                default:
                    System.out.println("Exiting...");
                    sc.close();
                    System.exit(0);
            }
        }
    }
}