#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "getline.h"

void reverse(char *s, int left, int right);
void trimString(char *s);

char *reverseWords(char *s)
{
    size_t n = strlen(s);
    reverse(s, 0, n - 1);

    int start = 0, end = 0;
    while (start < n)
    {
        while (start < n && isspace(s[start]))
            start++;
        end = start;

        while (end < n && !isspace(s[end]))
            end++;

        reverse(s, start, end - 1);
        start = end;
    }

    trimString(s);
    return s;
}

void trimString(char *s)
{
    if (s == NULL || *s == '\0')
    {
        return;
    }

    int i = 0, j = 0;

    while (s[i] != '\0' && isspace(s[i]))
        i++;

    int spaceFlag = 0;
    while (s[i] != '\0')
    {
        if (isspace(s[i]))
        {
            spaceFlag = 1;
            i++;
        }
        else
        {
            if (spaceFlag && j > 0)
            {
                s[j++] = ' ';
            }
            s[j++] = s[i++];
            spaceFlag = 0;
        }
    }
    s[j] = '\0';
    return;
}

int main(void)
{
    char *s = NULL;
    size_t len = 0;

    printf("Enter the string:\n");

    // getline allocates memory for s if necessary
    ssize_t nread = getline(&s, &len, stdin);

    if (nread == -1)
    {
        fprintf(stderr, "Error reading input\n");
        free(s);
        return 1;
    }

    reverseWords(s);
    printf("Reversed string:\n%s\n", s);
    free(s);
    return 0;
}

void reverse(char *s, int left, int right)
{
    while (left < right)
    {
        char c = s[left];
        s[left++] = s[right];
        s[right--] = c;
    }
}

/**
 * Working of strtok
 * // tokenize
    char s[] = "-abc-=-def";
    char *x;
    x = strtok(s, "-"); // x = "abc"
    printf("%s", x);
    x = strtok(NULL, "-="); // x = "def"
    printf("%s", x);

    x = strtok(NULL, "="); // x = NULL
    printf("%s", x);

    // s = "abc\0=-def\0"
 */