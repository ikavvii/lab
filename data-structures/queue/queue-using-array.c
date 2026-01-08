#include <stdio.h>

#define SIZE 3

struct queue
{
  int values[SIZE];
  int front;
  int rear;
};

void enqueue(int);
int dequeue();
int isEmpty();
int isFull();
void display();
void clearInputBuffer(void);
void resetQueue(void);

struct queue q;

int main()
{
  q.front = -1;
  q.rear = -1;
  int userChoice, data;
  char userActive = 'Y';

  while (userActive == 'Y' || userActive == 'y')
  {
    printf("\n------ QUEUE DATA STRUCTURE USING ARRAYS ------\n");
    printf("\n1. Enqueue");
    printf("\n2. Dequeue");
    printf("\n3. Display");
    printf("\n4. Exit");

    printf("\n\nEnter your choice: ");
    scanf("%d", &userChoice);

    switch (userChoice)
    {
    case 1:
      printf("\nEnter Data: ");
      scanf("%d", &data);
      enqueue(data);
      break;

    case 2:
      if (!isEmpty())
      {
        data = dequeue();
        printf("\n* %d was removed\n", data);
      }
      else
      {
        printf("\nQueue is Empty!\n");
      }
      break;
    case 3:
      display();
      printf("\n");
      break;
    case 4:
      printf("\n\tProgram was terminated!\n\n");
      return 1;
    default:
      printf("\n\tInvalid Choice\n");
    }
    printf("\nDo you want to continue? ");
    clearInputBuffer();
    scanf(" %c", &userActive);
  }
  return 0;
}

void clearInputBuffer()
{
  int c;
  while ((c = getchar()) != '\n' && c != EOF)
    ;
}

void resetQueue()
{
  if (isEmpty())
  {
    q.front = -1;
    q.rear = -1;
  }
}

int isEmpty()
{
  return (q.front == -1 || q.front > q.rear);
}

int isFull()
{
  return (q.rear == SIZE - 1);
}

void enqueue(int data)
{
  resetQueue();
  if (isFull())
  {
    printf("\nQueue is full!\n");
    return;
  }
  if (q.front == -1)
  {
    q.front++;
  }
  q.rear++;
  q.values[q.rear] = data;
  printf("\n* %d was inserted!\n", data);
}

int dequeue()
{
  int data = q.values[q.front];
  q.front += 1;
  resetQueue();
  return data;
}

void display()
{
  if (isEmpty())
  {
    printf("\nQueue is Empty\n");
    return;
  }
  printf("\n");
  int begin = q.front;
  while (begin <= q.rear)
  {
    printf("%d ", q.values[begin]);
    begin++;
  }
}