#include <stdio.h>
#include <stdlib.h>
//***************************FUNCTION DECLARATION*********************************
void create();
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
      create();
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