#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

#define STACK_MAX_SIZE 100

typedef struct Stack
{
    int data[STACK_MAX_SIZE];
    int min[STACK_MAX_SIZE];
    int top;
} Stack;

bool isFull(Stack *s)
{
    return s->top == STACK_MAX_SIZE - 1;
}

bool isEmpty(Stack *s)
{
    return s->top == -1;
}

int push(Stack *s, int item)
{
    if (isFull(s))
        return -1;
    s->data[++(s->top)] = item;
    if (s->top == 0)
    {
        s->min[s->top] = item;
    }
    else
    {
        s->min[s->top] = item < s->min[s->top - 1] ? item : s->min[s->top - 1];
    }
    return 0;
}

int pop(Stack *s, int *item)
{
    if (isEmpty(s))
        return -1;
    *item = s->data[s->top--];
    return 0;
}

int top(Stack *s, int *item)
{
    if (isEmpty(s))
        return -1;
    *item = s->data[s->top];
    return 0;
}

int getMin(Stack *s, int *item)
{
    if (isEmpty(s))
        return -1;
    *item = s->min[s->top];
    return 0;
}

void printStack(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack is empty\n");
        return;
    }
    printf("\nStack elements: \n");
    for (int i = 0; i <= s->top; i++)
    {
        printf("| %d ", s->data[i]);
    }
    printf("<-- top\n");
    printf("\nMin elements: \n");
    for (int i = 0; i <= s->top; i++)
    {
        printf("| %d ", s->min[i]);
    }
    printf("<-- top\n");
    printf("\n");
}

int main()
{
    Stack STACK = {.top = -1}; // designated initializers

    int status, item;
    enum
    {
        PUSH = 1,
        POP,
        TOP,
        GETMIN,
        EXIT
    } choice;

    printf("Min Stack Implementation\n");

    do
    {
        printf("1. push | 2. pop | 3. top | 4. getMin | 5. exit\n");
        printStack(&STACK);
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input. Exiting.\n");
            break;
        }
        switch (choice)
        {
        case PUSH:
            printf("Enter value to push: ");
            if (scanf("%d", &item) != 1)
            {
                printf("Invalid input. Exiting.\n");

                int ch;
                while ((ch = getchar()) != '\n' && ch != EOF)
                    ;
                return 1;
            }
            status = push(&STACK, item);
            if (status == -1)
            {
                printf("Stack overflow\n");
            }
            break;
        case POP:
            status = pop(&STACK, &item);
            if (status == 0)
            {
                printf("Popped element: %d\n", item);
            }
            else if (status == -1)
            {
                printf("Stack underflow\n");
            }
            break;
        case TOP:
            status = top(&STACK, &item);
            if (status != -1)
            {
                printf("Top element: %d\n", item);
            }
            else
            {
                printf("Stack is empty\n");
            }
            break;
        case GETMIN:
            status = getMin(&STACK, &item);
            if (status != -1)
            {
                printf("Minimum element: %d\n", item);
            }
            else
            {
                printf("Stack is empty\n");
            }
            break;
        case EXIT:
            printf("Exiting program.\n");
            break;
        default:
            printf("Invalid choice\n");
        }
    } while (choice != EXIT);

    return 0;
}