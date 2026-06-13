package arrays;

import java.util.Arrays;

public class RowColSum2dArray {
    static void main() {
        int[][] matrix = {{1, 2}, {3, 4}, {5, 6}};
        int[][] matrix1 = new int[matrix.length+1][matrix[0].length+1];
        int sum = 0;
        for (int i = 0; i< matrix.length; i++) {
            for (int j = 0; j< matrix[i].length; j++) {
                matrix1[i][j] = matrix[i][j];
                sum += matrix[i][j];
            }
            matrix1[i][matrix[i].length] = sum;
            sum = 0;
        }

        for (int i = 0; i < matrix1[0].length; i++) {
            for (int j = 0; j < matrix.length; j++) {
                sum += matrix1[j][i];
            }
            matrix1[matrix.length][i] = sum;
            sum = 0;
        }

        System.out.println(Arrays.deepToString(matrix));
        System.out.println(Arrays.deepToString(matrix1));
    }
}
