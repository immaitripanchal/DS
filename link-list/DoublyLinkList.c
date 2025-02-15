#include <stdio.h>
#include <stdlib.h>
//***************************FUNCTION DECLARATION*********************************
void create(int val);
void display();
void delete(int val);
void insertBefore(int val, int key);
void insertAfter(int val, int key);
void insertBeg(int val);
void insertEnd(int val);
void reverse();
void sort();
//***********************************NODE*****************************************
struct node
{
  struct node *prev;
  int data;
  struct node *next;
} *head = NULL;
//*********************************MAIN FUNCTION**********************************
int main()
{
  int choice, val, key;
  do
  {
    printf("\n-----------------MENU-----------------");
    printf("\n1.CREATE :");
    printf("\n2.DISPLAY :");
    printf("\n3.DELETE :");
    printf("\n4.INSERT BEFORE :");
    printf("\n5.INSERT AFTER :");
    printf("\n6.INSERT AT BEGINNING :");
    printf("\n7.INSERT AT END :");
    printf("\n8.REVERSE :");
    printf("\n9.SORTING :");
    printf("\n10.EXIT :");

    printf("Enter your choice :");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
      printf("Enter how many element you want :");
      scanf("%d", &val);
      create(val);
      break;

    case 2:
      display();
      break;

    case 3:
      printf("Enter a value which you want to delete :");
      scanf("%d", &val);
      delete (val);
      break;

    case 4:
      printf("Enter a value which you want to insert :");
      scanf("%d", &val);
      printf("Enter key :");
      scanf("%d", &key);
      insertBefore(val, key);
      break;

    case 5:
      printf("Enter value which you want to insert :");
      scanf("%d", &val);
      printf("Enter key :");
      scanf("%d", &key);
      insertAfter(val, key);
      break;

    case 6:
      printf("Enter value you want to insert :");
      scanf("%d", &val);
      insertBeg(val);
      break;

    case 7:
      printf("Enter value you want to insert :");
      scanf("%d", &val);
      insertEnd(val);
      break;

    case 8:
      reverse();
      break;

    case 9:
      sort();
      break;

    case 10:
      printf("Exiting program...........Thank you.........");
      break;
    }
  } while (choice != 10);
}
//*************************************FUNCTION DEFINITION***********************************
//*************************************CREATE FUNCTION********************************
void create(int val)
{
  struct node *new, *curr;
  int data;
  for (int i = 1; i <= val; i++)
  {
    printf("Enter value :");
    scanf("%d", &data);
    new = (struct node *)malloc(sizeof(struct node));
    new->data = data;
    new->prev = new->next = NULL;
    if (head == NULL)
    {
      head = new;
      curr = new;
    }
    else
    {
      new->prev = curr;
      curr->next = new;
      curr = new;
    }
  }
}
//*************************************DISPLAY***************************************
void display()
{
  struct node *curr;
  if (head == NULL)
  {
    printf("Link-list is empty :");
    return;
  }
  else
  {
    curr = head;
    while (curr != NULL)
    {
      printf("%d-->", curr->data);
      curr = curr->next;
    }
  }
}
//*************************************DELETE FUNCTION*******************************
void delete(int val)
{
  struct node *curr;
  if (head == NULL)
  {
    printf("Link-list is empty :");
    return;
  }

  curr = head;
  if (head->data == val)
  {
    head = curr->next;
    free(curr);
    head->prev = NULL;
    return;
  }
  else
  {
    while (curr != NULL && curr->data != val)
    {
      curr = curr->next;
    }
  }

  if (curr == NULL)
  {
    printf("value does not exist :");
    return;
  }
  if (curr->next == NULL)
  {
    curr->prev->next = NULL;
    free(curr);
    return;
  }
  curr->prev->next = curr->next;
  curr->next->prev = curr->prev;
  free(curr);
}
//*****************************INSERT BEFORE FUNCTION*****************************
void insertBefore(int val, int key)
{
  struct node *new, *curr;
  if (head == NULL)
  {
    printf("Link-list is empty :");
    return;
  }
  new = (struct node *)malloc(sizeof(struct node));
  new->data = val;
  new->next = new->prev = NULL;
  curr = head;
  if (head->data == key)
  {
    new->next = head;
    head->prev = new;
    head = new;
    return;
  }
  while (curr != NULL && curr->data != key)
  {
    curr = curr->next;
  }
  if (curr == NULL)
  {
    printf("value does not exist :");
    return;
  }
  new->prev = curr->prev;
  curr->prev->next = new;
  new->next = curr;
  curr->prev = new;
  return;
}
//****************************INSERT AFTER FUNCTION******************************************
void insertAfter(int val, int key)
{
}