#include <stdio.h>
#include <stdlib.h>
void insert(int value);
void display();
void sort();
void deleteNode(int value);
void createNode();
// ***************************NODE******************************
struct node
{
  int data;
  struct node *next;
} *head = NULL;
//******************************MAIN FUNCTION*******************************
int main()
{
  int choice, value;
  do
  {
    printf("\n[----------------MENU--------------]");
    printf("\n1.Insert :");
    printf("\n2.Display :");
    printf("\n3.shorting :");
    printf("\n4.delete node :");
    printf("\n5.Create new node :");
    printf("\n6.Exit :");
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
      printf("\nEnter a value which you want to delete :");
      scanf("%d", &value);
      deleteNode(value);
      break;

    case 5:
      createNode();
      break;

    case 6:
      printf("\nThank you.....");
      break;

    default:
      printf("\nInvalid choice");
      break;
    }

  } while (choice != 6);

  return 0;
}
//****************************INSERT FUNCTION*****************************
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
//**********************DISPLAY FUNCTION***********************
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
//******************************SORTING FUNCTION*****************************
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
    while (j != NULL)
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
//****************************DELETE NODE FUNCTION******************************
void deleteNode(int value)
{
  struct node *curr, *prev;
  if (head == NULL)
  {
    printf("\nList is empty");
    return;
  }
  curr = head;
  if (curr->data == value)
  {
    head = curr->next;
    free(curr);
    return;
  }
  while (curr != NULL && curr->data != value)
  {
    prev = curr;
    curr = curr->next;
  }
  if (curr == NULL)
  {
    printf("\nValue not found in the list");
    return;
  }
  prev->next = curr->next;
  free(curr);
}
//****************************CREATE NEW NODE FUNCTION******************************
void createNode()
{
  int n;
  struct node *curr;
  printf("\nEnter the number of nodes : ");
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
  {
    if (head == NULL)
    {
      head = (struct node *)malloc(sizeof(struct node));
      curr = head;
    }
    else
    {
      curr->next = (struct node *)malloc(sizeof(struct node));
      curr = curr->next;
    }
    printf("\nEnter data : ");
    scanf("%d", &curr->data);
    curr->next = NULL;
  }
}