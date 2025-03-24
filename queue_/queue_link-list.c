#include <stdio.h>
#include <stdlib.h>
//----------------------define struture of queue--------------
struct node
{
  int data;
  struct node *next;
} *front = NULL, *rear = NULL;
//----------------function declaration--------------------
void enqueue(int value);
int dequeue();
void display();
//--------------------main function----------------
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
      printf("deleted value is %d\n", value);
      display();
      break;

    case 3:
      display();
      break;

    case 4:
      printf("thank you...exit\n");
      break;

    default:
      printf("invalid choice :");
      break;
    }
  } while (choice != 4);
}
//----------------enqueue function------------------
void enqueue(int value)
{
  struct node *new;
  new = (struct node *)malloc(sizeof(struct node));
  if (new == NULL)
  {
    printf("overflow of queue..\n");
    return;
  }
  new->data = value;
  new->next = NULL;
  if (front == NULL)
  {
    front = rear = new;
    return;
  }
  rear->next = new;
  rear = new;
}
//--------------------dequeue function-------------
int dequeue()
{
  if (front == NULL)
  {
    printf("underflow of queue..\n");
    return 0;
  }
  if (front == rear)
  {
    free(front);
    front = rear = NULL;
    return 0;
  }
  struct node *temp = front;
  int value = temp->data;
  front = front->next;
  free(temp);
  return value;
}
//--------------------display function----------------
void display()
{
  if (front == NULL)
  {
    printf("underflow of queue...\n");
    return;
  }
  struct node *curr = front;
  while (curr != NULL)
  {
    printf("%d-->", curr->data);
    curr = curr->next;
  }
}