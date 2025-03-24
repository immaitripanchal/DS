#include <stdio.h>
#include <stdbool.h>
#define MAX 10
bool flag = true;
//------------------define queue------------------
int queue[MAX];
int front = -1;
int rear = -1;
//-----------------define function--------------
void enqueue(int value);
int dequeue();
void display();
//-------------------main function--------------
void main()
{
  int choice, value;
  do
  {
    printf("\n-------------MENU-------------\n");
    printf("1.ENQUEUE :\n");
    printf("2.DEQUEUE :\n");
    printf("3.DISPLAY :\n");
    printf("4.EXIT :\n");
    printf("--------------------------------\n");

    printf("Enter your choice :");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
      printf("Enter a value :");
      scanf("%d", &value);
      enqueue(value);
      break;

    case 2:
      value = dequeue();
      if (value)
      {
        printf("deleted value is %d\n", value);
        display();
      }
      break;

    case 3:
      display();
      break;

    case 4:
      printf("Thank you...exit\n");
      break;

    default:
      printf("Invalid choice :\n");
      break;
    }
  } while (choice != 4);
}
//-----------------function definition------------------
//-----------------enqueue function-----------------
void enqueue(int value)
{
  if (rear == MAX - 1)
  {
    printf("overflow of queue..\n");
    return;
  }
  if (front == -1)
  {
    front++;
  }
  queue[++rear] = value;
}
//-------------------dequeue function-------------------
int dequeue()
{
  if (front == -1)
  {
    printf("underflow of queue...\n");
    flag = false;
    return flag;
  }

  if (front == rear)
  {
    int temp = queue[rear];
    front = rear = -1;
    return temp;
  }
  return queue[front++];
}
//----------------display function------------------
void display()
{
  if (front == -1)
  {
    printf("underflow of queue..\n");
    return;
  }
  printf("Elements of queue :\n");
  for (int i = front; i <= rear; i++)
  {
    printf("%d ", queue[i]);
  }
}