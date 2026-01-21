package arrays;

import java.util.Arrays;

public class Array1D {
    static void main() {
        int [] array = {1,2, 3, 4, 5, 6, 7, 8, 9};
        System.out.println(Arrays.toString(array));

        System.out.println("Printing using enhanced for loop");
        for (int i : array) {
            System.out.print(i + " ");
        }
    }
}
