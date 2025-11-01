#include <stdio.h>
#include <stdlib.h>

struct SinglyLinkedListElement
{
    int value;
    struct SinglyLinkedListElement *next;
};

typedef struct SinglyLinkedListElement Node;

void print_reverse(Node *);
void print(Node *);

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
    {

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
    }
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
        break;
    }
    case 3:
    {
        printf("Enter number: ");
        scanf("%d", &variable);

        Node *node = malloc(sizeof(Node));
        if (!node)
            return EXIT_FAILURE;
        node->value = variable;
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

        break;
    }
    case 4:
    {
        if (head)
        {
            Node *temp = head;
            head = head->next;
            free(temp);
        }
        break;
    }
    case 5:
    {
        int position = 0;
        printf("Enter position (0-indexed): ");
        scanf("%d", &position);

        if (!head)
        {
            printf("List is empty.\n");
        }
        else if (position == 0)
        {
            Node *temp = head;
            head = head->next;
            free(temp);
        }
        else if (position < 0)
        {
            printf("Invalid position.\n");
        }
        else
        {
            int count = 0;
            curr = head;
            while (curr != NULL && curr->next != NULL && position - count > 1)
            {
                curr = curr->next;
                count++;
            }

            if (curr->next == NULL)
            {
                printf("Position out of bounds.\n");
            }
            else
            {
                Node *temp = curr->next;
                curr->next = temp->next;
                free(temp);
            }
        }
        break;
    }
    case 6:
    {
        if (!head)
        {
            printf("List is empty.\n");
        }
        else if (head->next == NULL)
        {
            Node *temp = head;
            head = NULL;
            free(temp);
        }
        else
        {
            curr = head;
            while (curr->next->next != NULL)
            {
                curr = curr->next;
            }
            Node *temp = curr->next;
            curr->next = NULL;
            free(temp);
        }
        break;
    }
    case 7:
    {

        if (head == NULL)
        {
            printf("List is empty.\n");
        }
        else
        {
            print_reverse(head);
        }
        break;
    }
    case 8:
    {
        variable = 0;

        curr = head;
        if (!head)
        {
            printf("No. of nodes: %d\n", variable);
        }
        else
        {
            while (curr != NULL)
            {
                curr = curr->next;
                variable++;
            }

            printf("No. of nodes: %d\n", variable);
        }
        break;
    }
    case 9:
    {
        Node *L1 = NULL, *L2 = NULL;
        printf("Merge two lists:\n");
        printf("Enter L1: ");
        while (scanf("%d", &variable) == 1)
        {
            Node *node = malloc(sizeof(Node));
            if (!node)
                return EXIT_FAILURE;
            node->value = variable;
            node->next = NULL;

            if (!L1)
            {
                L1 = node;
            }
            else
            {
                curr = L1;
                while (curr->next != NULL)
                {
                    curr = curr->next;
                }
                curr->next = node;
            }
            int c;
            if ((c = getchar()) == '\n')
            {
                break;
            }
        }
        print(L1);

        printf("\nEnter L2: ");
        while (scanf("%d", &variable) == 1)
        {
            Node *node = malloc(sizeof(Node));
            if (!node)
                return EXIT_FAILURE;
            node->value = variable;
            node->next = NULL;

            if (!L2)
            {
                L2 = node;
            }
            else
            {
                curr = L2;
                while (curr->next != NULL)
                {
                    curr = curr->next;
                }
                curr->next = node;
            }
            int c;
            if ((c = getchar()) == '\n')
            {
                break;
            }
        }
        print(L2);

        printf("\nMerging L1 with L2.. \n");

        // traverse L1 till last node and link with head node of L2
        if (!L1)
        {
            L1 = L2;
        }
        else
        {
            curr = L1;
            while (curr->next != NULL)
            {
                curr = curr->next;
            }
            curr->next = L2;
        }
        print(L1); // print merged list
        break;
    }
    case 10:
    {
        // TODO: sort a linked list
        Node *L = NULL;
        printf("Sort a linked list: \n");
        printf("Enter list elements: ");

        while (scanf("%d", &variable) == 1)
        {
            Node *node = malloc(sizeof(Node));
            if (!node)
                return EXIT_FAILURE;
            node->value = variable;
            node->next = NULL;

            if (!L)
            {
                L = node;
            }
            else
            {
                curr = L;

                while (curr->next != NULL)
                {
                    curr = curr->next;
                }

                curr->next = node;
            }

            // check for end of list elements input
            int c;
            if ((c = getchar()) == '\n')
            {
                break;
            }
        }
        printf("\nBefore: ");
        print(L);

        // TODO: iterative bottom-up merge sort 
        // O(nlogn) time and O(1) space

        printf("\nAfter: ");
        print(L);

        break;
    }
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

void print(Node *head)
{
    if (!head)
        return;
    printf(" --> %d", head->value);
    print(head->next);
}