import java.util.Scanner;

public class LabWorksheet1 {

    public static void main(String[] args) {
        System.out.println("=================================================");
        System.out.println("   Data Types, Overflow, Underflow & Operators   ");
        System.out.println("=================================================\n");

        System.out.println("--- 1. INTEGER OVERFLOW ---");
        int myInteger = Integer.MAX_VALUE;
        System.out.println("Max Integer: " + myInteger);
        System.out.println("Max + 1    : " + (myInteger + 1) + " (Wraps to Min)");
        System.out.println();

        System.out.println("--- 2. INTEGER UNDERFLOW ---");
        myInteger = Integer.MIN_VALUE;
        System.out.println("Min Integer: " + myInteger);
        System.out.println("Min - 1    : " + (myInteger - 1) + " (Wraps to Max)");
        System.out.println();

        System.out.println("--- 3. BYTE OVERFLOW ---");
        byte myByte = Byte.MAX_VALUE;
        System.out.println("Max Byte: " + myByte);
        // cast needed because Java promotes byte arithmetic to int
        myByte = (byte) (myByte + 1);
        System.out.println("Max + 1 : " + myByte + " (Overflows)");
        System.out.println();

        System.out.println("--- 4. SHORT UNDERFLOW ---");
        short myShort = Short.MIN_VALUE;
        System.out.println("Min Short: " + myShort);
        // Explicit cast required to force the underflow in the variable
        myShort = (short) (myShort - 1);
        System.out.println("Min - 1  : " + myShort + " (Underflows)");
        System.out.println();

        System.out.println("--- 5. LONG OVERFLOW & UNDERFLOW ---");
        long myLong = Long.MAX_VALUE;
        System.out.println("Max Long: " + myLong);
        System.out.println("Max + 1 : " + (myLong + 1) + " (Overflow)");

        myLong = Long.MIN_VALUE;
        System.out.println("Min Long: " + myLong);
        System.out.println("Min - 1 : " + (myLong - 1) + " (Underflow)");
        System.out.println();

        System.out.println("--- 6. FLOAT OVERFLOW/UNDERFLOW ---");
        float myFloat = Float.MAX_VALUE;
        System.out.println("Max Float: " + myFloat);
        // Infinity, not wrap-around
        System.out.println("Max * 1.1: " + (myFloat * 1.1f) + " (Overflow to Infinity)");

        myFloat = Float.MIN_VALUE; // Smallest positive nonzero value
        System.out.println("Min Float (Positive): " + myFloat);
        System.out.println("Min / 2: " + (myFloat / 2) + " (Underflow to 0.0)");
        System.out.println();

        System.out.println("--- 9. CHAR OVERFLOW ---");
        char myChar = Character.MAX_VALUE; // Value is 65535 ('\uffff')
        System.out.println("Max Char Numeric Value: " + (int) myChar);
        myChar = (char) (myChar + 1); // Wraps to 0
        System.out.println("Max + 1 (casted)      : " + (int) myChar);
        System.out.println();


        System.out.println("--- 10. BOOLEAN VALIDATION ---");
        boolean myBoolean = true;
        System.out.println("Boolean value: " + myBoolean);
        // Compilation Error:
        // System.out.println(myBoolean + 1); 
        System.out.println("Result: Arithmetic operations (+, -, *, /) are NOT allowed on booleans.");
        System.out.println();

        System.out.println("--- 11. ARITHMETIC OPERATORS ---");
        int a = 10;
        int b = 5;
        int result = (++a * b) + (a % b) - (a / -b);
        System.out.println("Expression: (++a * b) + (a % b) - (a / -b)");
        System.out.println("Result: " + result);
        System.out.println();

        System.out.println("--- 12. UNARY OPERATORS ---");
        int num1 = 10;
        System.out.println("Original: " + num1);
        System.out.println("Post-increment (num1++): " + (num1++)); // Prints 10
        System.out.println("Value after post-inc     : " + num1);     // Is 11

        int num2 = 10;
        System.out.println("Pre-increment (++num2) : " + (++num2)); // Prints 11
        System.out.println();

        System.out.println("--- 13. RELATIONAL OPERATORS (Grades) ---");
        int[] studentMarks = {100, 85, 65, 50, 30, 0};
        System.out.printf("| %-6s | %-10s | %-25s |%n", "MARKS", "GRADE", "LOGIC USED");
        System.out.println("----------------------------------------------");

        for (int marks : studentMarks) {
            String grade;
            String logic;
            if (marks == 100) { grade = "10"; logic = "marks == 100"; }
            else if (marks >= 81) { grade = "9"; logic = "marks >= 81"; }
            else if (marks > 60) { grade = "8"; logic = "marks > 60"; }
            else if (marks >= 41) { grade = "7"; logic = "marks >= 41"; }
            else if (marks != 0) { grade = "Fail"; logic = "marks < 41 && != 0"; }
            else { grade = "Absent"; logic = "Default"; }

            System.out.printf("| %-6d | %-10s | %-25s |%n", marks, grade, logic);
        }
        System.out.println();

        System.out.println("--- 14. LOGICAL OPERATORS ---");
        boolean hasExperience = true;
        boolean hasDegree = false;

        System.out.println("Has Experience && Degree: " + (hasExperience && hasDegree));
        System.out.println("Has Experience || Degree: " + (hasExperience || hasDegree));
        System.out.println("NOT Has Degree (!Degree): " + (!hasDegree));
        System.out.println();

        System.out.println("--- 15. BITWISE OPERATORS ---");
        int x = 12; // 1100
        int y = 25; // 11001

        System.out.println("12 & 25 (AND): " + (x & y));
        System.out.println("12 | 25 (OR) : " + (x | y));
        System.out.println("12 ^ 25 (XOR): " + (x ^ y));

        System.out.println("\n[Masking Example]");
        int largeNum = 0xABCD1234;
        System.out.println("Original Hex: " + Integer.toHexString(largeNum).toUpperCase());
        System.out.println("Mask first byte (0xFF)  : " + Integer.toHexString(largeNum & 0xFF).toUpperCase());
        System.out.println("Mask 16 bits (0xFFFF)   : " + Integer.toHexString(largeNum & 0xFFFF).toUpperCase());
        System.out.println();

        System.out.println("--- 16. SHIFT OPERATORS ---");
        int val = 10;
        System.out.println("Original: " + val);
        System.out.println("Left Shift (val << 2) : " + (val << 2)); // 40
        System.out.println("Right Shift (val >> 2): " + (val >> 2)); // 2

        System.out.println("\n[Testing Sign using Shift]");
        checkSignUsingShift(50);
        checkSignUsingShift(-50);
        System.out.println();

        System.out.println("=== THINKING & DEBUGGING EXERCISES ===");

        // 1. Overflow Prevention
        System.out.println("\n1. Overflow Prevention:");
        int maxInt = 2147483647;
        int overflowRes = maxInt + 10;
        System.out.println("Bad (int + int) : " + overflowRes);

        // Fix: Cast one operand to long BEFORE the addition
        long safeRes = (long) maxInt + 10;
        System.out.println("Good (long cast): " + safeRes);

        // 2. IEEE 754 Representation
        System.out.println("\n2. Float in IEEE Format:");
        float sampleFloat = 12.5f;
        // 12.5 in Binary is 1100.1
        // In IEEE 754: Sign=0, Exponent=127+3=130 (10000010), Mantissa=100100...
        int bits = Float.floatToIntBits(sampleFloat);
        String binaryString = Integer.toBinaryString(bits);

        // Pad with leading zeros to ensure 32 bits are shown
        binaryString = String.format("%32s", binaryString).replace(' ', '0');

        System.out.println("Float Value : " + sampleFloat);
        System.out.println("Raw Bits    : " + bits);
        System.out.println("Binary Rep  : " + binaryString);
        System.out.println("              | (Sign) | (Exponent) | (Mantissa)");
    }

    public static void checkSignUsingShift(int n) {
        // Unsigned right shift by 31 moves the sign bit to position 0
        int signBit = n >>> 31;
        if (signBit == 1) {
            System.out.println(n + " is NEGATIVE (Sign bit is 1)");
        } else {
            System.out.println(n + " is POSITIVE (Sign bit is 0)");
        }
    }
}