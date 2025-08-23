#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int n, first, last, temp; // what about unsigned integer?

    printf("Enter a positive integer: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Invalid input. Exiting..");
        exit(1);
    } else if (n <10) {
        printf("Entered a single digit number. Exiting..");
    }
    // printf("%d", n);

    int length = floor(log10(n)) + 1;
    // printf("%d", length);

    last = n % 10;

    // gets the first digit
    first = n;
    do {
        first /= 10;
    } while (first > 10);


    printf("%d %d\n",first, last);
    
    // check whether first or last digit is multiple of other
    if (first % last == 0)
        printf("The first digit %d is a multiple of last digit %d", first, last);
    else if (last % first == 0)
        printf("The last digit %d is a multiple of first digit %d", last, first);
    else 
        printf("Neither is a multiple of the other");

    return 0;
}
