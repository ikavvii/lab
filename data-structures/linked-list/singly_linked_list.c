#include <stdio.h>
#include <stdlib.h>

struct SinglyLinkedListElement
{
    int value;
    struct SinglyLinkedListElement *next;
};

typedef struct SinglyLinkedListElement Node;

void print_reverse(Node *);

int main()
{

    Node *head = NULL, *curr = NULL;

    int choice = 0, variable = 0;

menu:
    do
    {
        printf("\n\n\tSINGLY LINKED LIST OPERATIONS:\n\n\
        1.  To insert a new node at the beginning\n\
        2.  To insert a new node at a specified position\n\
        3.  To insert a new node at the end \n\
        4.  To delete a node at the beginning\n\
        5.  To delete a node from a specified position\n\
        6.  To delete a node at the end\n\
        7.  Display the list in reverse order\n\
        8.  Count the number of nodes\n\
        9.  Merging of two linked list\n\
        10. Sort a linked list\n\
        11. Swap nodes in a linked list without swapping data\n\
        12. Intersection point of two Linked Lists\n\
        13. Find length of loop in linked list (checks whether a\n\
            given Linked List contains loop and if loop is present\n\
            then returns count of nodes in  loop\n\
        14. Exit\n");
        printf("\nEnter choice: ");
        scanf("%d", &choice);
    } while (choice < 1 || choice > 14);

    switch (choice)
    {
    case 1:
        printf("Enter number: ");
        scanf("%d", &variable);

        Node *node = malloc(sizeof(Node));
        if (!node)
            return EXIT_FAILURE;
        node->value = variable;
        node->next = head;
        head = node;

        printf("Success: insert %d", variable);
        break;
    case 2:
    {

        int position = 0;
        printf("Enter position (0-indexed): ");
        scanf("%d", &position);

        printf("Enter number: ");
        scanf("%d", &variable);

        Node *node = malloc(sizeof(Node));
        if (!node)
            return EXIT_FAILURE;
        node->value = variable; 
        
        if (!head || position == 0)
        {
            node->next = head;
            head = node;
        }
        else
        {
            curr = head;

            int count = 0;
            while (curr->next != NULL && position - count > 1)
            {
                curr = curr->next;
                count++;
            }

            /* insert after curr (or at end if position exceeds length) */
            node->next = curr->next;
            curr->next = node;
        }
    }
    case 7:
        print_reverse(head);
        break;
    default:
        return EXIT_SUCCESS;
    }

    goto menu;

    return EXIT_SUCCESS;
}

void print_reverse(Node *head)
{
    if (!head)
        return;
    print_reverse(head->next);
    printf("%d <-- ", head->value);
}