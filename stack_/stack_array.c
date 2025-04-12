#include <stdio.h>
#include <stdbool.h>
#define MAX 10
//------------------------define stack-----------------------
int stack[MAX];
int top = -1;
bool flag = true;
//----------------------function declaration----------------------
void push(int value);
int pop();
int peep();
void display();
void change(int value, int pos);
//-------------------main function----------------------
void main()
{
  int value, pos, choice;

  do
  {
    printf("\n------------MENU------------\n");
    printf("1.PUSH :\n");
    printf("2.POP :\n");
    printf("3.PEEP :\n");
    printf("4.DISPLAY :\n");
    printf("5.CHANGE :\n");
    printf("6.EXIT :\n");
    printf("--------------------------\n");

    printf("Enter your choice :");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
      printf("Enter value :");
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
      printf("Enter postion between 1 to %d:\n", top + 1);
      scanf("%d", &pos);
      change(value, pos);
      display();
      break;

    case 6:
      printf("Thank you...Exit..\n");
      break;
    }

  } while (choice != 6);
}
//-----------------------push function-----------------------
void push(int value)
{
  if (top == MAX - 1)
  {
    printf("overflow...stack is full value can not be inserted..\n");
    return;
  }
  stack[++top] = value;
}
//-------------------pop function-----------------
int pop()
{
  if (top == -1)
  {
    printf("underflow....stack is empty...\n");
    flag = false;
    return flag;
  }
  return stack[top--];
}
//---------------peep function---------------
int peep()
{
  if (top == -1)
  {
    printf("underflow....stack is empty...\n");
    flag = false;
    return flag;
  }
  return stack[top];
}
//------------------display function--------------
void display()
{
  if (top == -1)
  {
    printf("stack underflow...\n");
    return;
  }
  printf("All element :\n");
  for (int i = 0; i <= top; i++)
  {
    printf("%d ", stack[i]);
  }
}
//-----------------change function-----------------
void change(int value, int pos)
{
  if (top == -1)
  {
    printf("stack underflow.....\n");
    return;
  }
  if (pos < 1 || pos > top + 1)
  {
    printf("incorrect position please enter valid position..\n");
    return;
  }
  stack[pos - 1] = value;
  return;
}
