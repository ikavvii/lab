// Third Largest Divisor

#include <stdio.h>

int tld(int n, int m, int k);
void test_tld();

int main()
{
    int n, m, k;
    
    test_tld(); // Call the test function
    
    printf("Enter three positive integers: ");
    int input = scanf("%d %d %d", &n, &m, &k);

    if (input != 3 || n <= 0 || m <= 0 || k <= 0) {
        printf("Invalid input. Please enter three positive integers.\n");
        return 1; // Exit with error code
    }
    printf("Third Largest Divisor: %d\n", tld(n, m, k));
}

int tld(int n, int m, int k)
{
    int p, count = 0;

    for (p = k; p >= 1; p--)
    {
        if (n % p == 0 && m % p == 0)
        {
            count++;
        }
        if (count == 3)
        {
            return p;
        }
    }


    return 0;
}

void test_tld() {
    // Test cases
    printf("Test Case 1: %s\n", tld(12, 18, 6) == 2 ? "passing" : "failing");
    printf("Test Case 2: %s\n", tld(30, 45, 15) == 3 ? "passing" : "failing");
    printf("Test Case 3: %s\n", tld(100, 80, 20) == 5 ? "passing" : "failing");
    printf("Test Case 4: %s\n", tld(7, 14, 7) == 0 ? "passing" : "failing");
    printf("Test Case 5: %s\n", tld(1, 1, 1) == 0 ? "passing" : "failing");
    printf("Test Case 6: %s\n", tld(20, 30, 10) == 2 ? "passing" : "failing");

    printf("All test cases executed.\n\n");

    return;
}
