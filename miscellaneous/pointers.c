#include <stdio.h>
int main()
{
    int a[] = {10, 5, 21, 51, 3, 2, 19}, *p;
    p = &a[0];
    printf("%d\n", *p); // It will print 10
    p = p + *(p + 4);
    printf("%d\n", *p); // What will be printed? (2) ____
    p = p + 1;
    printf("%d\n", *p); // It will print 3
    p = p + 2;
    printf("%d\n", *p); // It will print 19
    p = p - *(a + 1);
    printf("%d\n", *p); // What will be printed above the line? (5)___
    return 0;
}
