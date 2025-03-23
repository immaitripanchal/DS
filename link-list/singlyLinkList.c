#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
//***************************FUNCTION DECLARATION****************************
void insert();
void display();
void create();
void deleteAtFirst();
void deleteAtLast();
void deleteAtPosition(int value);
void insertAtFirst(int value);
void insertBefore(int value, int key);
void insertAfter(int value, int key);
void insertAtLast(int value);
void sort();
void reverse();
//***********************NODE***************************
struct node
{
  int data;
  struct node *next;
} *head = NULL;
//******************************MAIN FUNCTION*******************************
int main()
{
  int choice, val, key;
  do
  {
    printf("\n-------------------MENU---------------------");
    printf("\n1.INSERT NODE:");
    printf("\n2.DISPLAY LINK-LIST :");
    printf("\n3.CREATE LINK-LIST :");
    printf("\n4.DELETE AT FIRST :");
    printf("\n5.DELETER AT LAST :");
    printf("\n6.DELETE :");
    printf("\n7.INSERT AT FIRST :");
    printf("\n8.INSERT BEFORE : ");
    printf("\n9.INSERT AFTER :");
    printf("\n10.INSERT AT LAST :");
    printf("\n11.SORT LINK-LIST :");
    printf("\n12.REVERSE LINK-LIST :");
    printf("\n13.SPLIT :");
    printf("\n14.MERGE :");
    printf("\n15.EXIT :");
    printf("\n--------------------------------------------- :");

    printf("\nEnter your choice : ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
      insert();
      break;

    case 2:
      display();
      break;

    case 3:
      create();
      break;

    case 4:
      deleteAtFirst();
      break;

    case 5:
      deleteAtLast();
      break;

    case 6:
      printf("\nEnter the value to delete : ");
      scanf("%d", &val);
      deleteAtPosition(val);
      break;

    case 7:
      printf("\nEnter the value to insert at first : ");
      scanf("%d", &val);
      insertAtFirst(val);
      break;

    case 8:
      printf("\nEnter the value to insert : ");
      scanf("%d", &val);
      printf("\nEnter the value before which to insert : ");
      scanf("%d", &key);
      insertBefore(val, key);
      break;

    case 9:
      printf("\nEnter the value to insert : ");
      scanf("%d", &val);
      printf("\nEnter the value after which to insert : ");
      scanf("%d", &key);
      insertAfter(val, key);
      break;

    case 10:
      printf("\nEnter the value to insert at last : ");
      scanf("%d", &val);
      insertAtLast(val);
      break;

    case 11:
      sort();
      break;

    case 12:
      reverse();
      break;

    case 13:
      printf("Work in progress :");
      break;

    case 14:
      printf("Work in progress :");
      break;

    case 15:
      printf("\nExiting the program...Thank you.....");
      break;
    }

  } while (choice != 15);
}
//*******************************FUNCTION DEFINITION****************************
//**************************INSERT FUNCTION*******************************
void insert()
{
  struct node *new, *curr;
  new = (struct node *)malloc(sizeof(struct node));
  printf("\nEnter the value : ");
  scanf("%d", &new->data);
  new->next = NULL;
  if (head == NULL)
  {
    head = new;
  }
  else
  {
    curr = head;
    while (curr->next != NULL)
    {
      curr = curr->next;
    }
    curr->next = new;
  }
}
//**********************DISPLAY FUNCTION***********************
void display()
{
  if (head == NULL)
  {
    printf("\nList is empty");
    return;
  }
  struct node *curr;
  curr = head;
  while (curr != NULL)
  {
    printf("%d --> ", curr->data);
    curr = curr->next;
  }
}
//****************************CREATE FUNCTION******************************
void create()
{
  int n;
  printf("how many nodes you want to create :");
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
  {
    struct node *new, *curr;
    new = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter the value : ");
    scanf("%d", &new->data);
    new->next = NULL;
    if (head == NULL)
    {
      head = new;
    }
    else
    {
      curr = head;
      while (curr->next != NULL)
      {
        curr = curr->next;
      }
      curr->next = new;
    }
  }
}
//**************************DELETE AT FIRST FUNCTION***********************
void deleteAtFirst()
{
  if (head == NULL)
  {
    printf("\nList is empty");
    return;
  }
  else
  {
    struct node *curr;
    curr = head;
    head = curr->next;
    free(curr);
  }
}
//**************************DELETE AT LAST FUNCTION***********************
void deleteAtLast()
{
  if (head == NULL)
  {
    printf("\nList is empty");
    return;
  }
  else
  {
    struct node *curr, *prev;
    curr = head;
    while (curr->next != NULL)
    {
      prev = curr;
      curr = curr->next;
    }
    prev->next = NULL;
    free(curr);
  }
}
//**************************DELETE AT POSITION FUNCTION***********************
void deleteAtPosition(int value)
{
  if (head == NULL)
  {
    printf("\nList is empty");
    return;
  }
  else
  {
    struct node *curr, *prev;
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
      printf("\nElement not found");
      return;
    }
    prev->next = curr->next;
    free(curr);
  }
}
//**************************INSERT AT FIRST FUNCTION***********************
void insertAtFirst(int value)
{
  struct node *new;
  new = (struct node *)malloc(sizeof(struct node));
  new->data = value;
  new->next = head;
  head = new;
}
//**************************INSERT BEFORE FUNCTION***********************
void insertBefore(int value, int key)
{
  if (head == NULL)
  {
    printf("\nList is empty");
    return;
  }
  struct node *new, *curr, *prev;
  new = (struct node *)malloc(sizeof(struct node));
  new->data = value;
  new->next = NULL;
  if (head->data == key)
  {
    new->next = head;
    head = new;
    return;
  }
  curr = head;
  while (curr != NULL && curr->data != key)
  {
    prev = curr;
    curr = curr->next;
  }
  if (curr == NULL)
  {
    printf("\nElement not found");
    return;
  }
  new->next = curr;
  prev->next = new;
}
//**************************INSERT AFTER FUNCTION***********************
void insertAfter(int value, int key)
{
  struct node *new, *curr;
  new = (struct node *)malloc(sizeof(struct node));
  new->data = value;
  new->next = NULL;
  if (head->data == key)
  {
    new->next = head->next;
    head->next = new;
    return;
  }
  curr = head;
  while (curr != NULL && curr->data != key)
  {
    curr = curr->next;
  }
  if (curr == NULL)
  {
    printf("\nElement not found");
    return;
  }
  new->next = curr->next;
  curr->next = new;
}
//**************************INSERT AT LAST FUNCTION***********************
void insertAtLast(int value)
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
//**************************SORT FUNCTION***********************
void sort()

{
  struct node *i, *j, *min;

  if (head == NULL || head->next == NULL)
  {
    return;
  }
  for (i = head; i->next != NULL; i = i->next)
  {
    min = i;
    for (j = i->next; j != NULL; j = j->next)
    {
      if (j->data < min->data)
      {
        min = j;
      }
    }
    if (min != i)
    {
      int temp = i->data;
      i->data = min->data;
      min->data = temp;
    }
  }
}
//**************************REVERSE FUNCTION***********************
void reverse()
{
  struct node *prev, *current, *next;
  prev = NULL;
  current = head;
  while (current != NULL)
  {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }
  head = prev;
}