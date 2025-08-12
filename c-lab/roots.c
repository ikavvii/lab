#include <stdio.h>
#include <math.h>
#include <complex.h>

int main() {
    int a, b, c;
    double d;
    double x1, x2;

    printf("Enter a b c: ");
    scanf("%d %d %d", &a, &b, &c);

    // discriminant
    d = b * b - 4 * a * c;
    if (d > 0) {
        x1 = (-b + sqrt(d)) / (2 * a);
        x2 = (-b - sqrt(d)) / (2 * a);
    } else if (d == 0) {
        x1 = -b / (2 * a);
    } else {
        double complex z1 = (-b + csqrt(d)) / (2 * a);
        double complex z2 = (-b - csqrt(d)) / (2 * a);
        printf("Roots are complex: %.2f%+.2fi and %.2f%+.2fi\n", creal(z1), cimag(z1), creal(z2), cimag(z2));
    }

}