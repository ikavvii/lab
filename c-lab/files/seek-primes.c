#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;

    int n, p;

    fp = (FILE *)fopen("primes.txt", "r");

    while (1) {
        printf("Which prime? "); scanf("%d", &n);

        if (n < 1 || n > 1000) break;
    }
}