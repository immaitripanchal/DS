#include <stdio.h>
#include <ctype.h>
#include <string.h>
//-----------------define stack-------------------------
#define MAX 100
char stack[MAX];
int top = -1;
//-----------------------function declaration---------------------
void push(char value);
char pop();
int getPriority(char op);
void infixToPostfix(char infix[], char postfix[]);
//---------------------main function--------------
void main()
{
  char infix[MAX], postfix[MAX];
  printf("Enter infix expression :");
  gets(infix);
  postfix[0] = '\0';
  infixToPostfix(infix, postfix);
  printf("postfix expression is :");
  puts(postfix);
}
//------------------push function-----------
void push(char value)
{
  if (top == MAX - 1)
  {
    printf("Overflow stack..");
    return;
  }
  stack[++top] = value;
}
//------------------pop function-------------
char pop()
{
  if (top == -1)
  {
    printf("stack underflow..");
    return '\0';
  }
  return stack[top--];
}
//-------------------get priority function------------
int getPriority(char op)
{
  if (op == '$' || op == '^')
    return 3;
  else if (op == '*' || op == '/')
    return 2;
  else if (op == '%')
    return 1;
  else if (op == '+' || op == '-')
    return 0;
  else
    return -1;
}
//-------------------infix to postfix function----------------
void infixToPostfix(char infix[], char postfix[])
{
  int j = 0, i = 0;
  while (infix[i] != '\0')
  {
    if (infix[i] == '(')
    {
      push(infix[i]);
      i++;
    }
    else if (infix[i] == ')')
    {
      while (top == -1 || stack[top] != '(')
      {
        postfix[j] = pop();
        j++;
      }
      if (top == -1)
      {
        printf("invalid infix expression :");
        return;
      }
      pop();
      i++;
    }
    else if (isdigit(infix[i]) || isalpha(infix[i]))
    {
      postfix[j] = infix[i];
      j++;
      i++;
    }
    else if (infix[i] == '$' || infix[i] == '^' ||
             infix[i] == '*' || infix[i] == '/' ||
             infix[i] == '%' || infix[i] == '+' || infix[i] == '-')
    {
      while ((top != -1) && (stack[top] != '(') && (getPriority(stack[top]) >= getPriority(infix[i])))
      {
        postfix[j] = pop();
        j++;
      }
      push(infix[i]);
      i++;
    }

    else
    {
      printf("invalid infix expression :");
      return;
    }
  }

  while (top != -1 && stack[top] != '(')
  {
    postfix[j] = pop();
    j++;
  }
  postfix[j] = '\0';
}
