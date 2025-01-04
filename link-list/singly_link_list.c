#include <stdio.h>
void insert(int value);
void display();
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
    printf("[----------------MENU--------------]");
    printf("\n1.Insert :");
    printf("\n2.Display :");
    printf("\n3.Exit :");
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
      printf("\n");
      display();
      break;

    case 3:
      printf("\nThank you.....");
      break;

    default:
      printf("\nInvalid choice");
      break;
    }

  } while (choice != 3);

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
    printf("%d ", curr->data);
    curr = curr->next;
  }
}