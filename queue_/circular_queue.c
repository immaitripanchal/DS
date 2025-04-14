#include <stdio.h>
//----------------define structure of queue-------------
#define MAX 10
int queue[MAX];
int front = -1, rear = -1;
//-----------------function declaration----------------
void enqueue(int value);
int dequeue();
void display();
//-------------------main function--------------
void main()
{
  int choice, value;
  do
  {
    printf("\n------------MENU-----------\n");
    printf("1.ENQUEUE :\n");
    printf("2.DEQUEUE :\n");
    printf("3.DISPLAY :\n");
    printf("4.EXIT :\n");
    printf("--------------------------------\n");

    printf("Enter your choice :\n");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
      printf("Enter value :");
      scanf("%d", &value);
      enqueue(value);
      break;

    case 2:
      value = dequeue();
      break;

    case 3:
      display();
      break;

    case 4:
      printf("thank you...exit\n");
      break;

    default:
      printf("Invalid choice..\n");
      break;
    }
  } while (choice != 4);
}
//-----------------------enqueue function-----------------
void enqueue(int value)
{
  if ((front == 0 && rear == MAX - 1) || rear + 1 == front)
  {
    printf("overflow of queue..\n");
    return;
  }
  if (front == -1)
  {
    front = rear = 0;
  }
  else
  {
    rear = (rear + 1) % MAX;
  }
  queue[rear] = value;
}
//------------------dequeue function---------------------
int dequeue()
{
  if (front == -1)
  {
    printf("underflow of queue..\n");
    return 0;
  }
  int data = queue[front];
  if (rear == front)
  {
    rear = front = -1;
    return data;
  }
  front = (front + 1) % MAX;
  return data;
}
//----------------------display function---------------
void display()
{
  if (front == -1)
  {
    printf("underflow of queue...");
    return;
  }
  printf("All element of queue :\n");
  int i = front;
  while (1)
  {
    printf("%d ", queue[i]);
    if (i == rear)
      break;
    i = (i + 1) % MAX;
  }
}
