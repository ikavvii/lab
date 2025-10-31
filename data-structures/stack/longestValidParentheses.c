#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int data;
    struct node *next;
} node;

struct node *stack = NULL;

int longestValidParentheses(char *s)
{
    int result = 0;
    size_t n = strlen(s);
    int accumulator = 0, flag = 0;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
        {
            struct node *newNode = malloc(sizeof(struct node));
            newNode->data = 2;
            newNode->next = stack;
            stack = newNode;
        }
        else
        {

            if (stack == NULL && accumulator > 0)
            {
                flag = 1;
            }

            if (stack != NULL)
            {
                if (flag)
                {
                    result = result > accumulator ? result : accumulator;

                    accumulator = 0;
                }
                struct node *temp = stack;
                accumulator += temp->data;
                stack = stack->next;

                free(temp);
            }
        }
        printf("%d->", accumulator);
    }

    if (stack != NULL)
    {
        accumulator -= 2;
    }

    return result;
}

int main()
{
    char str[1024];

    printf("Enter the String: ");
    if (scanf("%1023s", str) != 1)
        return 1;

    printf("\nResult: %d\n", longestValidParentheses(str));
    return 0;
}