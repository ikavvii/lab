#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

char *reverse(char *s, int i, int j)
{

    while (i < j)
    {
        char temp = s[i];
        s[i++] = s[j];
        s[j--] = temp;
    }
    return s;
}

bool rotateString(char *s, char *goal)
{
    int sLength = strlen(s);
    if (sLength != strlen(goal))
        return false;

    for (int i = 0; i < sLength; i++)
    {
        reverse(s, 0, sLength - 1);
        reverse(s, 0, sLength - 2);
        if (strcmp(s, goal) == 0)
        {
            return true;
        }
    }

    return false;
}

int main()
{

    // char * A = malloc(strlen("abcde") + 1);
    // strcpy(A, "abcde");

    char A[] = "abcde";

    char B[] = "deabc";

    printf("%d", rotateString(A, B));

    // reverse from 0 thru until n - k
    // k=0,abcde => abcde => abcde
    // k=1,abcde => edcba => bcdea
    // k=2,abcde => edcba => cdeab
    // k=3,abcde => edcba => deabc

    return 0;
}

// abcde => edcba => bcdea => aedcb => cdeab => baedc => deabc => cbaed => eabcd => dcbae => abcde