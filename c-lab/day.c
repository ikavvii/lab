#include <stdio.h>

int main() {
    int j, m, a1, ns, as, f, rem = 0, temp = 0;
    printf("Enter a date: ");

    scanf("%d/%d/%d", &j, &m, &a1);
    // printf("%d %d %d", j, m, a1);
    if (m >= 3) {
        m -= 2;
        // printf("%d", m);
    } else if (m < 3) {
        m += 10; a1 -= 1;
    }

    for (int i = 1; i <= 10; i+=9) {
        rem = a1 % 10;
        temp += rem * i;
        a1 /= 10;
    }
    ns = temp;
    as = a1;    

    f = j + as + as/4 - 2 * ns + ns/4 + (26 * m - 2)/10;
    printf("%d", f);

    printf("%d", f % 7);

    return 0;
}