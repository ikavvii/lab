#include <stdio.h>
void main()
{
    int x;
    x = (printf("AA") || printf("BB"));
    printf("%d",x);
    printf("\n");
    
    x = (printf("AA") && printf("BB"));
    printf("%d",x);
}