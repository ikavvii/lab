#include <stdio.h>
#include <math.h>

int fact(int number);

int main () {
    double x, J_0x = 1;
    printf("Enter x: ");
    scanf("%lf", &x);

    // for first 20 terms
    for (int n = 1; n <= 20; n++) {
        // bessel function for first kind of order zero defined by
        J_0x += pow(-1, n) / fact(n) * pow(x/2, 2 * n);
    }
    printf("%lf", J_0x);
}


// returns factorial of a number
int fact(int number) {
    if (number == 0)
        return 1;
    return number * fact(number - 1);
}