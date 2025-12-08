#include <stdio.h>

int main() {

    char c;

    printf("Enter a character: ");
    scanf("%c", &c);

    if (c >= 'A' && c <= 'Z') {
        c += 32;
    }
    printf("\nThe output is %c\n", c);

}