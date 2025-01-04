#include <stdio.h>
#include <stdlib.h>
void insert(int value);
void display();
void sort();
struct node
{
  int data;
  struct node *next;
} *head = NULL;
int main()
{
  int choice, value;
  do
  {
    printf("\n[----------------MENU--------------]");
    printf("\n1.Insert :");
    printf("\n2.Display :");
    printf("\n3.shorting :");
    printf("\n4.Exit :");
    printf("\n[----------------------------------]");
    printf("\nEnter your choice : ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
      printf("\nEnter value :");
      scanf("%d", &value);
      insert(value);
      break;

    case 2:
      display();
      printf("\n");
      break;

    case 3:
      sort();
      break;

    case 4:
      printf("\nThank you.....");
      break;

    default:
      printf("\nInvalid choice");
      break;
    }

  } while (choice != 4);

  return 0;
}
void insert(int value)
{
  struct node *new, *curr;
  new = (struct node *)malloc(sizeof(struct node));
  new->data = value;
  new->next = NULL;
  if (head == NULL)
  {
    head = new;
    return;
  }
  curr = head;
  while (curr->next != NULL)
  {
    curr = curr->next;
  }
  curr->next = new;
}
void display()
{
  struct node *curr;
  curr = head;
  if (head == NULL)
  {
    printf("\nList is empty");
    return;
  }
  while (curr != NULL)
  {
    printf("%d-->", curr->data);
    curr = curr->next;
  }
}
void sort()
{
  if (head == NULL)
  {
    printf("\nList is empty");
    return;
  }
  struct node *i, *j;
  int temp;
  i = head;
  while (i->next != NULL)
  {
    j = i->next;
    while (j->next != NULL)
    {
      if (i->data > j->data)
      {
        temp = i->data;
        i->data = j->data;
        j->data = temp;
      }
      j = j->next;
    }
    i = i->next;
  }
}