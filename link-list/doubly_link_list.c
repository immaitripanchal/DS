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
  int choice, val;
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
    }
  } while (choice != 10);
}
//*************************************FUNCTION DEFINITION***********************************