#include <stdio.h>
#include <ctype.h>

int countValidWords(char *s)
{
    int result = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (islower(s[i]))
        {
        }
        if (s[i] == '-' && (islower(s[i - 1]) && islower(s[i + 1])))
        {
        }
        if (s[i] == '!' || s[i] == '.' || s[i] == ',')
        {
        }
    }
    return result;
}

int main()
{

    char s[200];
    int count;

    printf("Enter a string: \n");

    scanf("%[^\n]s", s);

    count = countValidWords(s);

    printf("\nNumber of words in given string are: %d\n", count + 1);

    return 0;
}