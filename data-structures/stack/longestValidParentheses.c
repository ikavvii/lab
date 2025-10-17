#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Stack
{
    char data;
    struct Stack *next;
} Stack;

Stack *top = NULL;

void push(char data)
{
    Stack *node = (Stack *)malloc(sizeof(Stack));
    if (!node)
        return;
    node->data = data;
    node->next = top;
    top = node;
}

int pop()
{
    if (!top)
        return 0;
    Stack *temp = top;
    top = top->next;
    free(temp);
    return 1;
}

int longestValidParentheses(char *s)
{
    int result = 0, curr = 0;
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] == '(')
        {
            push(s[i]);
        }
        else
        {
            int isPopped = pop();
            if (isPopped)
            {
                curr += 2;
            }
            else
            {
                result = result > curr ? result : curr;
                curr = 0;
            }
        }
        result = curr;
    }
    return result;
}

int main()
{
    char str[1024];

    printf("Enter the String: ");
    if (scanf("%1023s", str) != 1)
        return 1;

    printf("%d\n", longestValidParentheses(str));
    return 0;
}