#include "uthash.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

char **letterCombinations(char *digits, int *returnSize);

typedef struct button
{
    int number;
    char letters[5];
    UT_hash_handle hh;
} button;

button *buttons = NULL;

int main()
{

    int curr = 97;

    for (int i = 2; i <= 9; i++)
    {
        button *btn = malloc(sizeof(button));

        btn->number = i;
        int index = 0;
        int max_letters = i == 7 || i == 9 ? 4 : 3;
        for (char c = curr; index < max_letters; c++, index++)
        {
            btn->letters[index] = c;
        }

        btn->letters[index++] = '\0';

        curr += max_letters;

        HASH_ADD_INT(buttons, number, btn);
    }

    for (button *current = buttons; current != NULL; current = current->hh.next)
    {
        printf("%d: %s\n", current->number, current->letters);
    }

    char *digits = "23";
    int returnSize;
    char ** answer = letterCombinations(digits, &returnSize);


    button *current, *tmp;
    HASH_ITER(hh, buttons, current, tmp)
    {
        HASH_DEL(buttons, current);
        free(current);
    }

    return 0;
}

char **letterCombinations(char *digits, int *returnSize)
{

    char ** result = malloc(4 * strlen(digits) * sizeof(char*));

    if (result == NULL) {
        return NULL;
    }

    for (int i = 0; i < strlen((char*)result); i++) {
        result[i] = malloc(sizeof(char) * strlen(digits));
        if (result[i]==NULL) {
            return NULL;
        }
    }

    for (int i = 0; i < strlen(digits); i++)
    {

        int number = digits[i] - '0';

        button *btn;

        HASH_FIND_INT(buttons, &number, btn);

        if (btn != NULL)
        {
            for (int i = 0; i < strlen(btn->letters); i++)
            {
                printf("%c", btn->letters[i]);
            }
            printf("\n");
        }
    }

    return result;
}