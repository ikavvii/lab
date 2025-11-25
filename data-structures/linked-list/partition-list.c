#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *insert(struct ListNode *head, int index, int data)
{

    return head;
    
}

struct ListNode *delete(struct ListNode *head, int index)
{

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