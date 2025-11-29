#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *reverseList1(struct ListNode *head)
{
    struct ListNode *p = head,
                    *q = NULL,
                    *r = NULL;

    while (p != NULL)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }

    return q;
}

struct ListNode *reverseList(struct ListNode *head)
{
    struct ListNode *prev = NULL,
                    *curr = head,
                    *next = NULL;

    while (curr != NULL)
    {
        next = curr->next; // remember next node
        curr->next = prev; // reverse pointer
        prev = curr;       // move prev pointer
        curr = next;       // move curr pointer
    }

    return prev;
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

    head = reverseList1(head);

    print(head);
}