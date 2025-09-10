#include <stdio.h>

int main()
{
    int sum = 0;
    int i = 0;
    while (i < 5)
    {
        sum += i++;
    }
    printf("%d\n", sum);

    sum = 0;
    for(i = 1; i < 5; i++) sum = sum + i;
    printf("%d\n", sum);

    sum = 0;
    for(i = 0; i < 5; i++) sum = sum + i;
    printf("%d\n", sum);

    sum = 0;

    for(i = 0; i <= 5; i++) sum = sum + i;
    printf("%d\n", sum);

    sum = 0;

    for(i = 1; i <= 5; i++) sum = sum + i;
    printf("%d\n", sum);

    return 0;
}