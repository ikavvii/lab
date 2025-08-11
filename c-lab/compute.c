#include <stdio.h>
#include <math.h>

int main() {
    int x;
    double f;
    printf("Enter x: ");
    scanf("%d", &x);

    f = (pow(x, 3) - 2 * x * x  + x - 6.3) / (x * x + 0.05 * x + 3.14);
    printf("%lf", f);
}