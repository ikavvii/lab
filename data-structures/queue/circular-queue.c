// Circular Queue Implementation in C

#include <stdio.h>

#define MAX 5

typedef struct {
    int items[MAX];
    int front;
    int rear;
} CircularQueue;

void initQueue(CircularQueue* q) {
    q->front = -1;
    q->rear = -1;
}

int isFull(CircularQueue* q) {
    return ((q->rear + 1) % MAX == q->front);
}

int isEmpty(CircularQueue* q) {
    return (q->front == -1);
}

void enqueue(CircularQueue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->rear = (q->rear + 1) % MAX;
    q->items[q->rear] = value;
    printf("Inserted %d\n", value);
}

void dequeue(CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    int item = q->items[q->front];
    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX;
    }
    printf("Deleted %d\n", item);
}

int main() {
    CircularQueue q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);
    enqueue(&q, 60);

    dequeue(&q);
    dequeue(&q);

    return 0;
}