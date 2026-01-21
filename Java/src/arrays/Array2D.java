package arrays;

import java.util.Arrays;

public class Array2D {
    static void main() {
        int [][] arr;

        arr = new int[][] {{1,2,3}, {4,5,6},{7,8,9}};

        System.out.println(Arrays.deepToString(arr));

        System.out.println("Printing 2D array using for-each loop");
        for (int [] row : arr) {
            for (int col : row) {
                System.out.print(col + " ");
            }
            System.out.println();
        }
    }
}
