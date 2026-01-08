#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 5

typedef struct CircularQueue {
    int arr[MAX_SIZE];
    int front;
    int rear;
    int size;
} CircularQueue;

CircularQueue* createQueue() {
    CircularQueue* queue = (CircularQueue*)malloc(sizeof(CircularQueue));
    queue->front = -1;
    queue->rear = -1;
    queue->size = 0;
    return queue;
}

bool isEmpty(CircularQueue* queue) {
    return queue->size == 0;
}

bool isFull(CircularQueue* queue) {
    return queue->size == MAX_SIZE;
}

void enqueue(CircularQueue* queue, int data) {
    if (isFull(queue)) {
        printf("Queue is full! Cannot enqueue %d\n", data);
        return;
    }
    
    if (isEmpty(queue)) {
        queue->front = 0;
        queue->rear = 0;
    } else {
        queue->rear = (queue->rear + 1) % MAX_SIZE;
    }
    
    queue->arr[queue->rear] = data;
    queue->size++;
    printf("Enqueued: %d\n", data);
}

int dequeue(CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty! Cannot dequeue\n");
        return -1;
    }
    
    int data = queue->arr[queue->front];
    
    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % MAX_SIZE;
    }
    
    queue->size--;
    return data;
}

int peek(CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return -1;
    }
    return queue->arr[queue->front];
}

void display(CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return;
    }
    
    printf("Queue elements: ");
    int i = queue->front;
    for (int count = 0; count < queue->size; count++) {
        printf("%d ", queue->arr[i]);
        i = (i + 1) % MAX_SIZE;
    }
    printf("\n");
    printf("Front: %d, Rear: %d, Size: %d/%d\n", 
           queue->front, queue->rear, queue->size, MAX_SIZE);
}

void displayArrayState(CircularQueue* queue) {
    printf("Array state: [");
    for (int i = 0; i < MAX_SIZE; i++) {
        if (i >= queue->front && i <= queue->rear && queue->size > 0) {
            printf("%d", queue->arr[i]);
        } else if (queue->rear < queue->front && (i >= queue->front || i <= queue->rear)) {
            printf("%d", queue->arr[i]);
        } else {
            printf("_");
        }
        if (i < MAX_SIZE - 1) printf(", ");
    }
    printf("]\n");
}

int main() {
    CircularQueue* queue = createQueue();
    
    printf("=== Circular Queue Demo ===\n\n");
    
    printf("1. Enqueue 5 elements:\n");
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    enqueue(queue, 50);
    display(queue);
    displayArrayState(queue);
    
    printf("\n2. Try to enqueue when full:\n");
    enqueue(queue, 60);
    
    printf("\n3. Dequeue 2 elements:\n");
    printf("Dequeued: %d\n", dequeue(queue));
    printf("Dequeued: %d\n", dequeue(queue));
    display(queue);
    displayArrayState(queue);
    
    printf("\n4. Enqueue 2 more elements (demonstrates circular nature):\n");
    enqueue(queue, 60);
    enqueue(queue, 70);
    display(queue);
    displayArrayState(queue);
    
    printf("\n5. Front element:\n");
    printf("Front: %d\n", peek(queue));
    
    printf("\n6. Dequeue all elements:\n");
    while (!isEmpty(queue)) {
        printf("Dequeued: %d\n", dequeue(queue));
    }
    display(queue);
    
    printf("\n7. Try to dequeue from empty queue:\n");
    dequeue(queue);
    
    free(queue);
    return 0;
}
