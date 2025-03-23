#include <stdio.h>
#include <stdlib.h>
//-------------Function declaration--------------
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

//-----------------Define structure----------------
struct node
{
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
    printf("13. Exit");
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
      break;

    case 8:
      deleteAtEnd();
      break;

    case 9:
      printf("Enter key :");
      scanf("%d", &key);
      deleteBefore(key);
      break;

    case 10:
      printf("Enter key :");
      scanf("%d", &key);
      deleteAfter(key);
      break;

    case 11:
      printf("Enter key which you want to delete :");
      scanf("%d", &key);
      delete (key);
      break;

    case 12:
      countNodes();
      break;
    case 13:
      printf("Thank you...");
      break;
    }

  } while (choice != 13);
}
//---------------Function definition----------------
//---------------create function-------------------
void create(int value)
{
  struct node *new, *curr;
  for (int i = 1; i <= value; i++)
  {
    new = (struct node *)malloc(sizeof(struct node));
    printf("Enter value :");
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
//-----------------insert At beginning function----------------
void insertAtBeg(int value)
{
  struct node *new;
  new = (struct node *)malloc(sizeof(struct node));
  new->data = value;
  new->next = head;
  head = new;
}
//-----------------insert at last function------------
void insertAtEnd(int value)
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
//-----------------insert before function-------------------
void insertBefore(int value, int key)
{
  struct node *new, *curr, *prev;
  new = (struct node *)malloc(sizeof(struct node));
  new->data = value;
  new->next = NULL;
  if (head == NULL)
  {
    printf("Link-list is empty....");
    return;
  }
  else
  {
    if (head->data == key)
    {
      new->next = head;
      head = new;
      return;
    }
    else
    {
      curr = head;
      prev = curr;
      while (curr != NULL && curr->data != key)
      {
        prev = curr;
        curr = curr->next;
      }
      if (curr == NULL)
      {
        printf("key not found..");
        return;
      }
      new->next = curr;
      prev->next = new;
    }
  }
}
//----------------insert after function-------------
void insertAfter(int value, int key)
{
  struct node *new, *curr;
  new = (struct node *)malloc(sizeof(struct node));
  new->data = value;
  new->next = NULL;
  if (head == NULL)
  {
    printf("Link-list is empty....");
    return;
  }
  else
  {
    if (head->data == key)
    {
      new->next = head->next;
      head->next = new;
      return;
    }
    else
    {
      curr = head;
      while (curr != NULL && curr->data != key)
      {
        curr = curr->next;
      }
      if (curr == NULL)
      {
        printf("key doesn't exit...");
        return;
      }
      new->next = curr->next;
      curr->next = new;
    }
  }
}
//-----------------display function------------
void display()
{
  if (head == NULL)
  {
    printf("Empty link-list...");
    return;
  }
  struct node *curr;
  curr = head;
  while (curr != NULL)
  {
    printf("%d-->", curr->data);
    curr = curr->next;
  }
}
//-------------delete at beginning function------------
void deleteAtBeg()
{
  if (head == NULL)
  {
    printf("Empty Link-list...");
    return;
  }
  struct node *temp = head;
  head = temp->next;
  free(temp);
}
//---------------delete at last function----------
void deleteAtEnd()
{
  if (head == NULL)
  {
    printf("Empty link-list...");
    return;
  }
  if (head->next == NULL)
  {
    free(head);
    head = NULL;
    return;
  }
  struct node *temp = head;
  struct node *prev = NULL;
  while (temp->next != NULL)
  {
    prev = temp;
    temp = temp->next;
  }
  prev->next = NULL;
  free(temp);
}
//----------------delete before function-----------
void deleteBefore(int key)
{
  if (head == NULL || head->next == NULL || head->data == key)
  {
    printf("deletion can't be done....");
    return;
  }
  struct node *prev = NULL, *curr = head, *next = head->next;
  if (next->data == key)
  {
    head = head->next;
    free(curr);
    return;
  }
  while (next != NULL && next->data != key)
  {
    prev = curr;
    curr = next;
    next = next->next;
  }
  if (next == NULL)
  {
    printf("value doesn't exist...");
    return;
  }
  prev->next = curr->next;
  free(curr);
}
void deleteAfter(int key)
{
  if (head == NULL || head->next == NULL)
  {
    printf("deletion can't be done...");
    return;
  }
  struct node *curr = head;
  while (curr != NULL && curr->data != key)
  {
    curr = curr->next;
  }
  if (curr == NULL)
  {
    printf("key doesn't exist..");
    return;
  }
  struct node *temp = curr->next;
  curr->next = temp->next;
  free(temp);
}
//-------------------delete function-------------------
void delete(int key)
{
  if (head == NULL)
  {
    printf("link-list is empty...");
    return;
  }
  struct node *prev, *curr;
  curr = head;
  if (head->data == key)
  {
    head = curr->next;
    free(curr);
    return;
  }
  while (curr != NULL && curr->data != key)
  {
    prev = curr;
    curr = curr->next;
  }
  if (curr == NULL)
  {
    printf("value doesn't exist...");
    return;
  }
  prev->next = curr->next;
  free(curr);
}
//-----------------count nodes---------------
void countNodes()
{
  if (head == NULL)
  {
    printf("link-list is empty:");
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
  printf("Total Number of nodes is %d", count);
}
