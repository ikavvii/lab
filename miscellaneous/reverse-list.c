/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *reverseList(struct ListNode *head)
{
    struct ListNode *p = head,
                    *q = head->next,
                    *r = ;

    while (p != NULL)
    {
        r = q->next;
        q->next = p;
        p = p->next;
        q = r;
    }

    return p;
}

void print(struct ListNode *head)
{
    if (!head)
        return;
    printf(" --> %d", head->val);
    print(head->next);
}

int main()
{
    int variable;

    struct ListNode *head = NULL, *curr;

    for (int i = 0; i < 3; i++)
    {
        printf("Enter number: ");
        scanf("%d", &variable);
        struct ListNode *node = malloc(sizeof(struct ListNode));
        if (!node)
            return 0;
        node->val = variable;
        node->next = NULL;

        if (!head)
        {
            head = node;
        }
        else
        {
            curr = head;
            while (curr->next != NULL)
            {
                curr = curr->next;
            }
            curr->next = node;
        }
    }

    print(head);
    printf("\n");

    head = reverseList(head);

    print(head);
}