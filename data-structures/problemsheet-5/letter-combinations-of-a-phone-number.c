// O(4^N) time & O(n) space
// https://leetcode.com/problems/letter-combinations-of-a-phone-number/

#include "uthash.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

char **letterCombinations(char *digits, int *returnSize);
void getLetterCombinations(char *digits, int digitIndex, char *currentCombination,
                           char **result, int *resultSize);

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

    char *digits = "73";
    int returnSize;
    char **answer = letterCombinations(digits, &returnSize);

    // print the answer
    for (int i = 0; i < returnSize; i++)
    {
        char *str = answer[i];

        printf("%s", str);

        if (returnSize - i != 1)
            printf(", ");
    }
    printf("\n");

    button *current, *tmp;
    HASH_ITER(hh, buttons, current, tmp)
    {
        HASH_DEL(buttons, current);
        free(current);
    }

    for (int i = 0; i < returnSize; i++)
    {
        free(answer[i]);
    }

    free(answer);

    return 0;
}

char **letterCombinations(char *digits, int *returnSize)
{

    if (strlen(digits) == 0)
    {
        *returnSize = 0;
        return NULL;
    }

    // get total number of combinations possible
    *returnSize = 0;
    for (int i = 0; i < strlen(digits); i++)
    {
        *returnSize = *returnSize ? *returnSize : 1;
        int number = digits[i] - '0';
        if (number == 7 || number == 9)
        {
            *returnSize *= 4;
        }
        else
        {
            *returnSize *= 3;
        }
    }

    // allocate memory for array of strings (array of pointers)
    char **result = malloc(*returnSize * sizeof(char *));

    if (result == NULL)
    {
        return NULL;
    }

    // allocate memory for individual strings in created string array
    for (int i = 0; i < *returnSize; i++)
    {
        result[i] = malloc(sizeof(char) * (strlen(digits) + 1));
        if (result[i] == NULL)
        {
            return NULL;
        }
    }

    // recursive function
    int resultIndex = 0;
    char *currentCombination = malloc((strlen(digits) + 1) * sizeof(char));
    currentCombination[0] = '\0';

    getLetterCombinations(digits, 0, currentCombination, result, &resultIndex);

    free(currentCombination);

    return result;
}

void getLetterCombinations(char *digits, int digitIndex, char *currentCombination,
                           char **result, int *resultIndex)
{

    if (digitIndex == strlen(digits))
    {
        strcpy(result[(*resultIndex)++], currentCombination);
        return;
    }

    int number = digits[digitIndex] - '0';
    button *btn;
    HASH_FIND_INT(buttons, &number, btn);

    for (int i = 0; i < strlen(btn->letters); i++)
    {
        int len = strlen(currentCombination);

        currentCombination[len] = btn->letters[i];
        currentCombination[len + 1] = '\0';

        getLetterCombinations(digits, digitIndex + 1, currentCombination, result,
                              resultIndex);

        currentCombination[len] = '\0';
    }
}