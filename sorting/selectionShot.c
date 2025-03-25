#include <stdio.h>
#include <limits.h>
int main()
{
  int n;
  printf("Enter how many element you want :");
  scanf("%d", &n);

  int arr[n];

  for (int i = 0; i < n; i++)
  {
    printf("Enter %d element :", i + 1);
    scanf("%d", &arr[i]);
  }

  int min, idx;
  for (int i = 0; i < n - 1; i++)
  {
    min = INT_MAX;
    idx = -1;
    for (int j = i; j < n; j++)
    {
      if (min > arr[j])
      {
        min = arr[j];
        idx = j;
      }
    }
    int temp = arr[idx];
    arr[idx] = arr[i];
    arr[i] = temp;
  }

  for (int i = 0; i < n; i++)
  {
    printf("%d ", arr[i]);
  }
}