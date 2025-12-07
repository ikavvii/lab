#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        newNode->next = newNode;
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != *head) {
        temp = temp->next;
    }
    newNode->next = *head;
    temp->next = newNode;
    *head = newNode;
}

void insertAtEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        newNode->next = newNode;
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != *head) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = *head;
}

void deleteNode(Node** head, int key) {
    if (*head == NULL) return;
    
    Node* temp = *head;
    Node* prev = NULL;
    
    if ((*head)->data == key && (*head)->next == *head) {
        free(*head);
        *head = NULL;
        return;
    }
    
    if ((*head)->data == key) {
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = (*head)->next;
        Node* toDelete = *head;
        *head = (*head)->next;
        free(toDelete);
        return;
    }
    
    prev = *head;
    temp = (*head)->next;
    while (temp != *head && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    
    if (temp == *head) return;
    
    prev->next = temp->next;
    free(temp);
}

void display(Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    Node* temp = head;
    printf("Circular List: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");
}

void freeList(Node** head) {
    if (*head == NULL) return;
    Node* temp = *head;
    Node* next;
    do {
        next = temp->next;
        free(temp);
        temp = next;
    } while (temp != *head);
    *head = NULL;
}

int main() {
    Node* head = NULL;
    
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtBeginning(&head, 5);
    
    display(head);
    
    deleteNode(&head, 20);
    printf("After deleting 20:\n");
    display(head);
    
    freeList(&head);
    return 0;
}
