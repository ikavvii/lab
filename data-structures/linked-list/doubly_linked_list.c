/**
 * Author
 */

#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};

struct node *head = NULL;

void insert_at_beginning(int);
void insert_at_end(int);
void insert_at_position(int, int);
void delete_from_beginning();
void delete_from_position(int);
void delete_from_end();
void print_from_beginning();
void print_from_end(struct node *);
void search_data(int);
void update_node_data(int, int);
void list_sort();

struct node *create_node(int);
int size_of_list();
int getData();
int getPosition();
void empty_list_message();
void memory_error_message();
void invalid_position_message();

int main()
{

    char user_active = 'Y';
    int user_choice;
    int data, position;

    while (user_active == 'y' || user_active == 'Y')
    {

        printf("\n\n------ Doubly Linked List -------\n");
        printf("\n1. Insert a node at the beginning");
        printf("\n2. Insert a node at the end");
        printf("\n3. Insert a node at the given position");
        printf("\n\n4. Delete a node from the beginning");
        printf("\n5. Delete a node from the end");
        printf("\n6. Delete a node from the given position");
        printf("\n\n7. Print list from the beginning");
        printf("\n8. Print list from the end");
        printf("\n9. Search a node data");
        printf("\n10. Update a node data");
        printf("\n11. Sort the list");
        printf("\n12. Exit");
        printf("\n\n------------------------------\n");

        printf("\nEnter your choice: ");
        scanf("%d", &user_choice);

        printf("\n------------------------------\n");

        switch (user_choice)
        {
        case 1:
            printf("\nInserting a node at beginning");
            break;

        default:
            break;
        }
    }
}

void memory_error_message()
{
    printf("\nMemory was not allocated!\n");
}

void invalid_position_message()
{
    printf("\nInvalid position\n");
}

void empty_list_message()
{
    printf("\nList is Empty!\n");
}

int size_of_list()
{
    struct node *temp = head;
    int count = 0;

    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    return count;
}

struct node *create_node(int data)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    if (new_node == NULL)
    {
        return NULL;
    }
    else
    {
        new_node->prev = NULL;
        new_node->data = data;
        new_node->next = NULL;
    }
}

void insert_at_beginning(int data)
{
    struct node *new_node = create_node(data);
    if (new_node == NULL)
    {
        memory_error_message();
        return;
    }
    else if (head == NULL)
    {
        head = new_node;
    }
    else
    {
        head->prev = new_node;
        new_node->next = head;
        head = new_node;
    }

    printf("\n* Node with data %d was inserted \n", data);

    return;
}

void insert_at_end(int data)
{
    struct node *new_node = create_node(data);

    if (new_node == NULL)
    {
        memory_error_message();
        return;
    }
    else if (head == NULL)
    {
        head = new_node;
    }
    else
    {
        struct node *temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->prev = temp;
    }

    printf("\n* Node with data %d was inserted \n", data);

    return;
}

void insert_at_position(int data, int pos)
{
    struct node *new_node = create_node(data);
    int size = size_of_list();

    if (new_node == NULL)
    {

        memory_error_message();
        return;
    }

    else if (head != NULL && (pos < 1 || pos > size))
    {
        invalid_position_message();
        return;
    }
    else if (head == NULL && pos == 1)
    {
        head = new_node;
    }
    else if (head != NULL && pos == 1)
    {
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
    }
    else
    {
        struct node *temp = head;
        int count = 1;

        while (++count < pos)
        {
            temp = temp->next;
        }
        temp->next->prev = new_node;
        new_node->next = temp->next;

        temp->next = new_node;
        new_node->prev = temp;
    }

    printf("\n* Node with data %d was inserted \n", data);
}

void delete_from_beginning()
{
    if (head == NULL)
    {
        empty_list_message();
        return;
    }

    struct node *temp = head;

    head = head->next;
    int data = temp->data;
    free(temp);

    printf("\n* Node with data %d was deleted \n", data);

    return;
}

void delete_from_end()
{
    if (head == NULL)
    {
        empty_list_message();
        return;
    }

    struct node *temp = head;
    int data = 0;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    if (temp->prev == NULL)
    {
        head = NULL;
    }
    else
    {
        temp->prev->next = temp->next;
    }

    data = temp->data;
    free(temp);

    printf("\n* Node with data %d was deleted \n", data);

    return 0;
}


