#include <stdio.h>
#include <math.h>

double fact(int number);

int main () {
    double x, J_0x = 0;
    printf("Enter x: ");
    scanf("%lf", &x);

    // for first 20 terms
    for (int n = 0; n <= 20; n++) {
        // bessel function for first kind of order zero defined by
        J_0x += pow(-1, n) * pow(x/2.0, 2 * n) / pow(fact(n), 2);
    }
    printf("J0(%lf) = %.10lf\n", x, J_0x);
}


// returns factorial of a number
double fact(int number) {
    if (number == 0)
        return 1.0;
    double result = 1.0;
    for (int i = 1; i<=number;i++) {
        result *= i;
    }
    return result;
}