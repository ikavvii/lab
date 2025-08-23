#include <stdio.h>

int main()
{
    int number, remainder, quotient = 0, divisor = 2, sum = 1;

    printf("Enter a number: ");
    scanf("%d", &number);

    int temp = number;

    printf("%d+", sum);
    do
    {
        remainder = number % divisor;

        if (!remainder) {
            quotient = number / divisor;
            sum += quotient + divisor;
            printf("%d+%d+", divisor, quotient);
            divisor++;
        } else {
            divisor++;
        }
    } while (quotient > divisor);
    printf("\b = %d", sum);
    printf("\nIs perfect: %s\n", sum == number?"true":"false");
}