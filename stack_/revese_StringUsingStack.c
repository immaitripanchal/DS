#include <stdio.h>
#include <string.h>
//-------------define stack------------
#define MAX 50
int stack[MAX];
int top = -1;
//-------------------function declaration----------
void push(int value);
char pop();
//------------------main function-----------
void main()
{
  char str[MAX];
  printf("Enter string :");
  scanf("%s", str);

  int i = 0;
  while (str[i] != '\0')
  {
    push(str[i]);
    i++;
  }

  printf("Reversed string :\n");
  while (top != -1)
  {
    char ch = pop();
    printf("%c", ch);
  }
}
//--------------push function-------------
void push(int value)
{
  if (top == MAX - 1)
  {
    printf("stack overflow...");
    return;
  }
  stack[++top] = value;
}
//-------------pop function--------------
char pop()
{
  if (top == -1)
  {
    printf("stack underflow....");
    return '\0';
  }
  return stack[top--];
}