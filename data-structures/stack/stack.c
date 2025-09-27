#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define STACK_MAX_SIZE 100

typedef struct Stack
{
    int data[STACK_MAX_SIZE];
    int min[STACK_MAX_SIZE];
    int TOP;
} Stack;

Stack STACK = {.TOP = -1}; // designated initializers

bool isFull(Stack *s)
{
    return s->TOP == STACK_MAX_SIZE - 1;
}

bool isEmpty(Stack *s)
{
    return s->TOP == -1;
}

void push(Stack *s, int item)
{
    if (isFull(s))
        return;
    s->data[++(s->TOP)] = item;
    if (s->TOP == 0)
    {
        s->min[s->TOP] = item;
    }
    else
    {
        s->min[s->TOP] = item < s->min[s->TOP - 1] ? item : s->min[s->TOP - 1];
    }
    return;
}

void pop(Stack *s)
{
    if (isEmpty(s))
        return;
    (s->TOP)--;
}

int top(Stack *s)
{
    return isEmpty(s) ?  : s->data[s->TOP];
}

int getMin(Stack *s)
{
    return isEmpty(s) ? (int)NULL : s->min[s->TOP];
}

int main()
{
    char operations[][10] = {"push", "push", "push", "getMin", "pop", "top", "getMin"};

    int arguments[][1] = {{-2}, {0}, {-3}, {}, {}, {}, {}};

    int output[7];

    for (int i = 0; i < 7; i++)
    {
        if (strcmp(operations[i], "push") == 0)
        {
            push(&STACK, arguments[i][0]);
            output[i] = NULL;
        }
        else if (strcmp(operations[i], "pop") == 0)
        {
            pop(&STACK);
            output[i] = NULL;
        }
        else if (strcmp(operations[i], "top") == 0)
        {
            output[i] = top(&STACK);
        }
        else if (strcmp(operations[i], "getMin") == 0)
        {
            output[i] = min(&STACK);
        }
        else
        {
            continue;
        }
    }

    int expectedOutput[] = {NULL, NULL, NULL, -3, NULL, 0, -2};

    for (int i = 0; i < 7; i++)
    {
        if (output[i] != expectedOutput[i])
        {
            printf("Test case %d failed: expected %d, got %d\n", i + 1, expectedOutput[i], output[i]);
            return 1;
        }
    }

    printf("All test cases passed!\n");

    return 0;
}