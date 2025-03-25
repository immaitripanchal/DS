#include <stdio.h>
#include <stdlib.h>
//-----------------define structure--------------
struct node
{
  int data;
  struct node *lptr, *rptr;
} *root = NULL;
//-------------------function declaration---------------
void insert(int value);
void preOrder(struct node *r);
void inOrder(struct node *r);
void postOrder(struct node *r);
//---------------------main function-------------------
void main()
{
  int choice, value;
  do
  {
    printf("\n-----------MENU-----------\n");
    printf("1.Insert :\n");
    printf("2.Inorder :\n");
    printf("3.Preorder :\n");
    printf("4.Postorder :\n");
    printf("5.Exit :\n");
    printf("-----------------------------\n");

    printf("Enter your choice :");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
      printf("Enter value :");
      scanf("%d", &value);
      insert(value);
      break;

    case 2:
      inOrder(root);
      break;

    case 3:
      preOrder(root);
      break;

    case 4:
      postOrder(root);
      break;

    case 5:
      printf("thank you..exit..\n");
      break;

    default:
      printf("invalid choice :");
      break;
    }
  } while (choice != 5);
}
//-------------------------insert function------------------
void insert(int value)
{
  struct node *new, *curr, *prev;
  int d;
  new = (struct node *)malloc(sizeof(struct node));
  new->data = value;
  new->lptr = new->rptr = NULL;
  if (root == NULL)
  {
    root = new;
    return;
  }
  curr = root;
  while (curr != NULL)
  {
    if (value < curr->data)
    {
      prev = curr;
      curr = curr->lptr;
      d = 0;
    }
    else if (value > curr->data)
    {
      prev = curr;
      curr = curr->rptr;
      d = 1;
    }
    else
    {
      printf("duplicate value can not be allow :");
      return;
    }
  }
  if (d == 0)
  {
    prev->lptr = new;
  }
  else
  {
    prev->rptr = new;
  }
}
//--------------------preorder function--------------------
void preOrder(struct node *r)
{
  if (r == NULL)
  {
    return;
  }
  printf("%d ", r->data);
  preOrder(r->lptr);
  preOrder(r->rptr);
}
//----------------------inorder function------------------
void inOrder(struct node *r)
{
  if (r == NULL)
  {
    return;
  }
  inOrder(r->lptr);
  printf("%d ", r->data);
  inOrder(r->rptr);
}
//--------------------postorder function-------------------
void postOrder(struct node *r)
{
  if (r == NULL)
  {
    return;
  }
  postOrder(r->lptr);
  postOrder(r->rptr);
  printf("%d ", r->data);
}
