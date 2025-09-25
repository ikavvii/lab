#include <stdio.h>

int main() {
    char c;
    printf("\nEnter the character:");
    scanf(" %c", &c);

    if (c >= 'A' && c <= 'Z') {
        c = c + 32;
    }
    printf("\nThe output character is %c", c);
}