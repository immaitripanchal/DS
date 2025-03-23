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
} *first = NULL, *second = NULL;

//-----------------Main function------------------
int main()
{
  int choice, value, key;
  do
  {
    printf("[------------MENU------------]\n");
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
    }
  } while (choice != 12);
}
