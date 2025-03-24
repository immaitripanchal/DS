#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//--------------------stack declaration--------------------
struct node
{
  int data;
  struct node *next;
} *top = NULL;

bool flag = true;
//------------------function declaration---------------
void push(int value);
int pop();
int peep();
void display();
void change(int value, int pos);
//---------------------main function----------------
void main()
{
  int choice, pos, value;
  do
  {
    printf("\n------------MENU----------\n");
    printf("1.PUSH :\n");
    printf("2.POP :\n");
    printf("3.PEEP :\n");
    printf("4.DISPLAY :\n");
    printf("5.CHANGE :\n");
    printf("6.EXIT :\n");
    printf("------------------------------\n");

    printf("Enter your choice :\n");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
      printf("Enter value :\n");
      scanf("%d", &value);
      push(value);
      display();
      break;

    case 2:
      value = pop();
      if (value)
      {
        printf("pop value is %d\n", value);
        display();
      }
      break;

    case 3:
      value = peep();
      if (value)
        printf("peep value is %d\n", value);
      break;

    case 4:
      display();
      break;

    case 5:
      printf("Enter new value :");
      scanf("%d", &value);
      printf("enter value which you want to replace :");
      scanf("%d", &pos);
      change(value, pos);
      break;

    case 6:
      printf("Thank you....exit\n");
      break;
    }

  } while (choice != 6);
}
//------------------push function-------------------
void push(int value)
{
  struct node *new;
  new = (struct node *)malloc(sizeof(struct node));
  if (new == NULL)
  {
    printf("stack overflow...\n");
    return;
  }
  new->data = value;
  new->next = top;
  top = new;
}
//-------------------pop function----------
int pop()
{
  if (top == NULL)
  {
    printf("stack underflow...");
    flag = false;
    return flag;
  }
  struct node *temp;
  int data;
  temp = top;
  top = top->next;
  data = temp->data;
  free(temp);
  return data;
}
//-------------------------peep function---------------
int peep()
{
  if (top == NULL)
  {
    printf("stack underflow...");
    flag = false;
    return flag;
  }
  return (top->data);
}
//--------------------display function----------------
void display()
{
  if (top == NULL)
  {
    printf("stack underflow.....");
    return;
  }
  struct node *curr = top;
  printf("stack element :\n");
  while (curr != NULL)
  {
    printf("%d-->", curr->data);
    curr = curr->next;
  }
}
//-------------------change function-------------------
void change(int value, int pos)
{
  struct node *curr;
  curr = top;
  while (curr != NULL && curr->data != pos)
  {
    curr = curr->next;
  }
  if (curr == NULL)
  {
    printf("value doesn't found :");
    return;
  }
  curr->data = value;
}
