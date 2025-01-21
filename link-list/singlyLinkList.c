#include <stdio.h>
#include <stdlib.h>
//***************************FUNCTION DECLARATION****************************
void insert();
void display();
void create();
void deleteAtFirst();
void deleteAtLast();
void deleteAtPosition(int value);
//***********************NODE***************************
struct node
{
  int data;
  struct node *next;
} *head = NULL;
//******************************MAIN FUNCTION*******************************
int main()
{
  int choice;
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

  } while (choice != 15);
}
//*******************************FUNCTION DEFINITION****************************
//**************************INSERT FUNCTION*******************************
void insert()
{
  struct node *new, *curr;
  new = (struct node *)malloc(sizeof(struct node));
  printf("\nEnter the value : ");
  scanf("%d", new->data);
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
  while (curr->next != NULL)
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
    while (curr->next != NULL && curr->data != value)
    {
      prev = curr;
      curr = curr->next;
    }
    if (curr->next == NULL)
    {
      printf("\nElement not found");
      return;
    }
    prev->next = curr->next;
    free(curr);
  }
}
