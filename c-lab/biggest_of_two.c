#include <stdio.h>

int main() {
    int i, j, k, flag;

    printf("Enter two numbers: ");
    scanf("%d %d", &i, &j);

    k = i - j;
    flag = (k >> 31) & 1;

    printf("%d", (i * !flag) + (j * flag));
}