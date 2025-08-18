#include <stdio.h>

int main() {
    int j, m, a1, ns, as, f, rem = 0, temp = 0;
    char * days_of_week[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", \
        "Thursday", "Friday", "Saturday"};

    printf("Enter a date: ");
    scanf("%d/%d/%d", &j, &m, &a1);

    if (m >= 3) {
        m -= 2;
    } else if (m < 3) {
        m += 10; a1 -= 1;
    }

    ns = a1 / 100;
    as = a1 % 100;

    f = j + as + as/4 - 2 * ns + ns/4 + (26 * m - 2)/10;

    printf("%s", days_of_week[f%7]);

    return 0;
}