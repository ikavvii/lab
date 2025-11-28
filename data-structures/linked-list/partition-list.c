#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *insert(struct ListNode *head, int index, int data)
{
    struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
    if (!node)
        return NULL;

    node->val = data;
    node->next = NULL;

    if (!head || index == 0)
    {
        node->next = head;
        head = node;
    }
    else
    {
        struct ListNode *curr = head;

        int count = 0;
        while (curr->next != NULL && index - count > 1)
        {
            curr = curr->next;
            count++;
        }

        node->next = curr->next;
        curr->next = node;
    }

    return head;
}

struct ListNode *delete(struct ListNode *head, int index)
{
    if (!head && index < 0) return NULL;
    else if (index == 0) {
        struct ListNode *temp = head;
        head=head->next;
        free(temp);
    }
    else {
        int count = 0;
        
    }

    return head;
}

struct ListNode *partition(struct ListNode *head, int x)
{

    return head;
}

void print(struct ListNode *head)
{
    if (head == NULL)
        return;
    printf(" --> %d", head->val);
    print(head->next);
}

int main()
{
    struct ListNode *head = NULL;

    insert(head, 0, 1);
    insert(head, 1, 4);
    insert(head, 2, 3);
    insert(head, 3, 2);
    insert(head, 4, 5);
    insert(head, 5, 2);

    print(head);

    head = partition(head, 3);

    print(head);

    return 0;
}