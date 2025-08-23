#include <stdio.h>

int main() {
 int a, a1, a2, rem = 0, temp = 0;

    scanf("%d", &a);
    printf("%d\n", a);

    for (int i = 1; i <= 10; i+=9) {
        rem = a % 10;
        temp += rem * i;
        a /= 10;
    }
    a1 = temp;
    a2 = a;

    printf("%d\n", a1);
    printf("%d", a2);
    return 0;
}