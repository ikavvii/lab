#include <stdio.h>
#include <string.h>

/**
 * The function lengthOfLastWord takes a null-terminated string s as input and
 * returns the length of the last word in the string, 
 * where a word is defined as a contiguous sequence of non-space characters. 
 * The implementation iterates backward through the string, 
 * skipping trailing spaces, and counts the characters of the last word 
 * until a space or the beginning of the string is encountered.
 */
int lengthOfLastWord(char *s)
{
    int result = 0;
    for (int i = strlen(s); i >= 0; i--)
    {
        if (s[i] == ' ' && result == 0)
        {
            continue;
        }
        else if (s[i] != ' ' && s[i] != '\0')
        {
            result++;
        }
        else if (s[i] == ' ')
        {
            break;
        }
    }

    return result;
}

int main()
{
    // char *s = "Hello World";
    char *s = "luffy is still joyboy";

    printf("%d", lengthOfLastWord(s));
}
