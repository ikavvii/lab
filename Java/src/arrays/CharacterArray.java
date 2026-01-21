package arrays;

import java.util.Arrays;

public class CharacterArray {
    static void main() {
        char[] name1 = "Kavin Manohanran".toCharArray();
        char [] name2 = Arrays.copyOf(name1, name1.length);
        Arrays.sort(name1);
        System.out.println(Arrays.toString(name1));
        Arrays.sort(name2, 0, 5);
        System.out.println(Arrays.toString(name2));

        int index = Arrays.binarySearch(name1, 'K');

        if (index >= 0) {
            System.out.println(name1[index] + " at " + index);
        } else {
            int insertionPoint = -(index + 1);
            System.out.println("This key can be inserted at " + insertionPoint);
        }
    }
}
