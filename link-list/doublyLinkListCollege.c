#include <stdio.h>
#include <stdlib.h>
//-------------function declaration---------
void create(int value);
void insertAtBeg(int value);
void insertAtEnd(int value);
void insertBefore(int value, int key);
void insertAfter(int value, int key);
void display();
void deleteAtBeg();
void deleteAtEnd();
void deleteBefore(int key);
void deleteAfter(int key);
void delete(int key);
void countNodes();
void sort();
void reverse();

//------------- define structure------------
struct node
{
  struct node *prev;
  int data;
  struct node *next;
} *head = NULL;

//-----------------Main function------------------
int main()
{
  int choice, value, key;
  do
  {
    printf("\n[------------MENU------------]\n");
    printf("1. Create :\n");
    printf("2. Insert At Beginning :\n");
    printf("3. Insert At End :\n");
    printf("4. Insert Before :\n");
    printf("5.Insert After :\n");
    printf("6. Display :\n");
    printf("7.Delete At Beginning :\n");
    printf("8. Delete At End :\n");
    printf("9. Delete Before :\n");
    printf("10. Delete After :\n");
    printf("11.Delete :\n");
    printf("12.Count Of Nodes :\n");
    printf("13.Sort :\n");
    printf("14.reverse :\n");
    printf("15. Exit :\n");
    printf("-----------------------------\n");

    printf("Enter your choice :");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
      printf("Enter how many nodes you want :");
      scanf("%d", &value);
      create(value);
      break;

    case 2:
      printf("Enter value :");
      scanf("%d", &value);
      insertAtBeg(value);
      break;

    case 3:
      printf("Enter value :");
      scanf("%d", &value);
      insertAtEnd(value);
      break;

    case 4:
      printf("Enter value :");
      scanf("%d", &value);
      printf("Enter key :");
      scanf("%d", &key);
      insertBefore(value, key);
      break;

    case 5:
      printf("Enter value :");
      scanf("%d", &value);
      printf("Enter key :");
      scanf("%d", &key);
      insertAfter(value, key);
      break;

    case 6:
      display();
      break;

    case 7:
      deleteAtBeg();
      display();
      break;

    case 8:
      deleteAtEnd();
      display();
      break;

    case 9:
      printf("Enter key :");
      scanf("%d", &key);
      deleteBefore(key);
      display();
      break;

    case 10:
      printf("Enter key :");
      scanf("%d", &key);
      deleteAfter(key);
      display();
      break;

    case 11:
      printf("Enter key which you want to delete :");
      scanf("%d", &key);
      delete (key);
      display();
      break;

    case 12:
      countNodes();
      break;

    case 13:
      sort();
      display();
      break;

    case 14:
      reverse();
      display();
      break;

    case 15:
      printf("Thank you...");
      break;
    }

  } while (choice != 15);
}
//---------------Function definition----------------
//-----------------create function------------------
void create(int value)
{
  struct node *curr, *new;
  for (int i = 1; i <= value; i++)
  {
    new = (struct node *)malloc(sizeof(struct node));
    printf("Enter value :");
    scanf("%d", &new->data);
    new->next = new->prev = NULL;
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
//---------------------insert at beginning function---------------------
void insertAtBeg(int value)
{
  struct node *new;
  new = (struct node *)malloc(sizeof(struct node));
  new->data = value;
  new->prev = new->next = NULL;
  if (head == NULL)
  {
    head = new;
    return;
  }
  new->next = head;
  head->prev = new;
  head = new;
}
//----------------------insert at end----------------------
void insertAtEnd(int value)
{
  struct node *new, *curr;
  new = (struct node *)malloc(sizeof(struct node));
  new->data = value;
  new->prev = new->next = NULL;
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
  new->prev = curr;
}
//----------------------insert before--------------------
void insertBefore(int value, int key)
{
  if (head == NULL)
  {
    printf("link-list is empty...");
    return;
  }
  struct node *new, *curr;
  new = (struct node *)malloc(sizeof(struct node));
  new->data = value;
  new->prev = new->next = NULL;

  if (head->data == key)
  {
    new->prev = head;
    head->prev = new;
    head = new;
    return;
  }
  curr = head;
  while (curr != NULL && curr->data != key)
  {
    curr = curr->next;
  }
  if (curr == NULL)
  {
    printf("key not found...");
    return;
  }
  new->prev = curr->prev;
  new->next = curr;
  curr->prev->next = new;
  curr->prev = new;
}
//-----------------------insert after function-----------------------
void insertAfter(int value, int key)
{
  if (head == NULL)
  {
    printf("Link-list is empty...");
    return;
  }
  struct node *curr, *new;
  new = (struct node *)malloc(sizeof(struct node));
  new->data = value;
  new->prev = new->next = NULL;
  curr = head;
  while (curr != NULL && curr->data != key)
  {
    curr = curr->next;
  }
  if (curr == NULL)
  {
    printf("key doesn't exist...");
    return;
  }
  if (curr->next == NULL)
  {
    curr->next = new;
    new->prev = curr;
    return;
  }
  new->prev = curr;
  new->next = curr->next;
  curr->next = new;
  new->next->prev = new;
}
//------------------display function-----------------------
void display()
{
  if (head == NULL)
  {
    printf("link-list is empty..");
    return;
  }
  struct node *curr;
  curr = head;
  while (curr != NULL)
  {
    printf("<--%d-->", curr->data);
    curr = curr->next;
  }
}
//------------------delete at beginning--------------
void deleteAtBeg()
{
  if (head == NULL)
  {
    printf("Link-list is empty...");
    return;
  }
  struct node *temp;
  temp = head;
  head = head->next;
  free(temp);
  head->prev = NULL;
}
//----------------------delete at end-----------------------
void deleteAtEnd()
{
  if (head == NULL)
  {
    printf("link-list is empty..");
    return;
  }
  struct node *curr;
  curr = head;
  while (curr->next != NULL)
  {
    curr = curr->next;
  }
  curr->prev->next = NULL;
  free(curr);
}
//------------------delete before---------------------
void deleteBefore(int key)
{
  if (head == NULL || head->data == key || head->next == NULL)
  {
    printf("deletion can not be done...");
    return;
  }
  if (head->next->data == key)
  {
    deleteAtBeg();
    return;
  }
  struct node *curr = head->next, *prev, *beforePrev;
  while (curr != NULL && curr->data != key)
  {
    curr = curr->next;
  }
  if (curr == NULL)
  {
    printf("value doesn't exist...");
    return;
  }
  prev = curr->prev;
  beforePrev = prev->prev;

  beforePrev->next = curr;
  curr->prev = beforePrev;
  free(prev);
}
//------------------delete after function--------------------
void deleteAfter(int key)
{
  if (head == NULL || head->next == NULL)
  {
    printf("deletion can not be done...");
    return;
  }
  struct node *curr;
  curr = head;
  while (curr != NULL && curr->data != key)
  {
    curr = curr->next;
  }
  if (curr == NULL)
  {
    printf("key not found ...");
    return;
  }
  if (curr->next == NULL)
  {
    return;
  }
  struct node *temp = curr->next;
  curr->next = temp->next;
  if (temp->next != NULL)
    temp->next->prev = temp->prev;
  free(temp);
}
//-----------------delete function--------------
void delete(int key)
{
  if (head == NULL)
  {
    printf("link-list is empty..");
    return;
  }
  struct node *curr;
  curr = head;
  if (head->data == key)
  {
    head = head->next;
    head->prev = NULL;
    free(curr);
    return;
  }
  while (curr != NULL && curr->data != key)
  {
    curr = curr->next;
  }
  if (curr == NULL)
  {
    printf("value doesn't exist...");
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
//-----------------count nodes function-------------------
void countNodes()
{
  if (head == NULL)
  {
    printf("link-list is empty..");
    return;
  }
  struct node *curr;
  curr = head;
  int count = 0;
  while (curr != NULL)
  {
    count++;
    curr = curr->next;
  }
  printf("total number of nodes is %d", count);
  return;
}
//---------------------sort function-------------
void sort()
{
  if (head == NULL)
  {
    printf("link-list is empty...");
    return;
  }
  struct node *i, *j;
  i = head;
  while (i->next != NULL)
  {
    j = i->next;
    while (j != NULL)
    {
      if (j->data < i->data)
      {
        int temp = j->data;
        j->data = i->data;
        i->data = temp;
      }
      j = j->next;
    }
    i = i->next;
  }
}
//----------------------reverse function-----------------
void reverse()
{
  if (head == NULL || head->next == NULL)
  {
    return;
  }
  struct node *curr, *next;
  curr = head;
  head = NULL;
  while (curr != NULL)
  {
    next = curr->next;
    curr->next = head;
    curr->prev = next;
    head = curr;
    curr = next;
  }
}
