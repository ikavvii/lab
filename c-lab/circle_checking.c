#include <stdio.h>
#include <math.h>

int main()
{
    double x, y, r = 5, d;

    printf("Enter two numbers: ");
    scanf("%lf %lf", &x, &y);

    d = sqrt(x * x + y * y);
    // printf("%lf", x);

    if (d < r)
    {
        printf("Point inside the circle");
    }
    else if (d > r)
    {
        printf("Point outside the circle");
    }
    else
    {
        printf("Point on the circle");
    }

    return 0;
}