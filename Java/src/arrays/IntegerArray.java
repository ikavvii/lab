package arrays;

import java.util.Arrays;

public class IntegerArray {
    static void main() {
        int[] a = {10, 20, 30, 40, 50};

        int [] b = Arrays.copyOf(a, a.length);
        System.out.println(Arrays.toString(b));
        int [] c = Arrays.copyOfRange(a, 1, 3);
        System.out.println(Arrays.toString(c));

    }
}
