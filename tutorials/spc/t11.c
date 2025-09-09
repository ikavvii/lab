#include <stdio.h>
#include <conio.h>
void main()
{
    // clrscr();
    switch (printf("a"), printf("abc"), printf("ab"))
    {
    case 1:
        switch (printf("first"))
            break;
    case 2:
        switch (printf("second"))
            break;
    default:
        switch (printf("third"))
            break;
    }
}