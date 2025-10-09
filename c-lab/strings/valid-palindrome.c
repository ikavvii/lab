#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

/**
 * The isPalindrome function 
 * checks whether a given null-terminated string s is a palindrome, 
 * ignoring non-alphanumeric characters and
 * treating uppercase and lowercase letters as equivalent. 
 * It uses two pointers to traverse the string from both ends, 
 * comparing characters until the middle is reached 
 * or a mismatch is found.
 */
bool isPalindrome(char *s)
{
    char *left = s, *right = s + strlen(s) - 1;

    while (left < right)
    {
        if (!isalnum(*left))
        {
            left++;
            continue;
        }
        if (!isalnum(*right))
        {
            right--;
            continue;
        }

        if (tolower(*left) != tolower(*right))
            return false;

        left++;
        right--;
    }
    return true;
}

int main()
{
    char *s = s = "A man, a plan, a canal: Panama";
    printf("%d", isPalindrome(s));
}