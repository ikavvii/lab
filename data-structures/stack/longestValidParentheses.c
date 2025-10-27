#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node {
    char data;
    struct node* next;
} node;

struct node* stack = NULL;

int longestValidParentheses(char* s) {
    int result = 0;
    size_t n = strlen(s);
    int tempResult = 0, accumulator = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            struct node* newNode = malloc(sizeof(struct node));
            newNode->data = '(';
            newNode->next = stack;
            stack = newNode;
            result = result > accumulator ? result : accumulator;

        } else {
            if (stack == NULL) {
                result = result > accumulator ? result : accumulator;
                accumulator = 0;
            } else {
                struct node* tempNode = stack;
                stack = stack->next;
                free(tempNode);

                accumulator += 2;
                if (stack == NULL) {
                    result = result > accumulator ? result : accumulator;
                } else {
                    

                }
            }
        }
    }
   
    result = result > accumulator ? result : accumulator;
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