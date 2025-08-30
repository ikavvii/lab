#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{

  char s[50], t[50];

  printf("Enter two strings: ");
  scanf("%s", s);
  scanf("%s", t);

  if (strlen(s) != strlen(t))
  {
    printf("Not an anagram.\n");
    return 0;
  }

  int i;
  int freq[26] = {0};
  for (i = 0; s[i] != '\0'; i++)
  {

    if (isalpha(s[i]))
    {
      freq[tolower(s[i]) - 'a']++;
    }
    if (isalpha(t[i]))
    {
      freq[tolower(t[i]) - 'a']--;
    }
  }

  for (i = 0; i < 26; i++)
  {
    if (freq[i] != 0)
    {
      printf("Not an anagram.\n");
      return 0;
    }
  }

  printf("Anagram.\n");
  return 0;
}