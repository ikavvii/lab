#include <stdio.h>
#include <math.h>
#include <complex.h>

int main() {
    int a, b, c;
    double d;
    double complex x1, x2;

    printf("Enter constants of quadratic equation a b c: ");
    scanf("%d %d %d", &a, &b, &c);

    // discriminant
    d = b * b - 4 * a * c;
    
    x1 = (-b + csqrt(d + 0.0 * I)) / (2.0 * a);
    x2 = (-b - csqrt(d + 0.0 * I)) / (2.0 * a);

    if (cimag(x1) == 0 && cimag(x2) == 0) {
        if (creal(x1) == creal(x2)) {
            printf("Roots are real and equal: %.2f", creal(x1));
        } else {
            printf("Roots are real and distinct: %.2f, and %.2f", creal(x1), creal(x2));
        }
    } else {
        printf("Roots are complex: %.2f%+.2fi and %.2f%+.2fi\n", \
            creal(x1), cimag(x1), creal(x2), cimag(x2));
    }
    return 0;

}