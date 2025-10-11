#include <stdio.h>
#define MAX_SIZE 5

struct stack
{
  int stk[MAX_SIZE];
  int top;
};

struct stack st;

int isEmpty(void);
int isFull(void);
void push(int);
int pop(void);
int peek(void);
void display(void);
void clearInputBuffer(void);

int main()
{
  st.top = -1;

  char userContinue = 'Y';
  int userChoice;

  while (userContinue == 'Y' || userContinue == 'y')
  {
    printf("\n------ STACK DATA STRUCTURE USING ARRAY ------");
    // printf("Top @ %d", st.top);
    printf("\n1. Push the data");
    printf("\n2. Pop the data");
    printf("\n3. Peek the data");
    printf("\n4. Display Stack");
    printf("\n5. Exit");

    printf("\n\nEnter your choice: ");
    scanf("%d", &userChoice);

    switch (userChoice)
    {
    case 1:
      printf("\n\nEnter data: ");
      scanf("%d", &userChoice);
      push(userChoice);
      break;

    case 2:
      if (!isEmpty())
      {
        int data = pop();
        printf("\nValue %d is popped", data);
      }
      else
      {
        printf("\n\tStack is Empty!");
      }
      break;

    case 3:
      if (!isEmpty())
      {
        int data = peek();
        printf("\nValue %d was peeked", data);
      }
      else
      {
        printf("\n\tStack is Empty!");
      }
      break;

    case 4:
      display();
      break;

    case 5:
      printf("\n\tProgram Terminated!\n");
      userContinue = 'N';
      break;

    default:
      printf("\n\tInvalid Choice!");
    }

    if (userChoice != 5)
    {
      printf("\n\nDo you want to continue? ");
      // fflush(stdin);
      clearInputBuffer();

      scanf(" %c", &userContinue);
    }
  }
}

void clearInputBuffer(void)
{
  int c;
  while ((c = getchar()) != '\n' && c != EOF)
    ;
}

int isFull()
{
  return (st.top + 1 == MAX_SIZE);
}

int isEmpty()
{
  return (st.top == -1);
}

void push(int data)
{
  if (isFull())
  {
    printf("\nStack Overflow!");
  }
  else
  {
    st.stk[++st.top] = data;
    printf("\n* %d was inserted", data);
  }
}

int pop()
{
  return st.stk[st.top--];
}

int peek()
{
  return st.stk[st.top];
}

void display()
{
  if (isEmpty())
  {
    printf("\n\tStack is Empty!");
    return;
  }

  for (int i = st.top; i >= 0; i--)
  {
    printf("\n\t%d", st.stk[i]);
  }
}