package arrays;

import java.util.Arrays;

public class EmployeeSanity {
    static void main() {

        int NO_WORKING_DAYS = 6;
        int SANITY = 100;
        int ENERGY_REDUCED_BY = 10;
        int[] energy = new int[NO_WORKING_DAYS];

        Arrays.setAll(energy, ithDay -> SANITY - ENERGY_REDUCED_BY * ithDay);

        System.out.println(Arrays.toString(energy));
    }
}
