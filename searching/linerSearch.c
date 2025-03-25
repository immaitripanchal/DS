#include <stdio.h>
#include <stdbool.h>
int main()
{
  int n;
  printf("Enter how many element you want in array :");
  scanf("%d", &n);

  int arr[n];

  for (int i = 0; i < n; i++)
  {
    printf("Enter %d element :", i + 1);
    scanf("%d", &arr[i]);
  }

  int search;
  printf("Enter element you want to search :");
  scanf("%d", &search);

  bool flag = false;
  int idx = -1;
  for (int i = 0; i < n; i++)
  {
    if (arr[i] == search)
    {
      flag = true;
      idx = i;
      break;
    }
  }

  if (flag == true)
  {
    printf("element found at %d position", idx + 1);
  }
  else
  {
    printf("Element not found :");
  }
}
