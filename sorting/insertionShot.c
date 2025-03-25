#include <stdio.h>
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

  for (int i = 1; i < n; i++)
  {
    int j = i;
    while (j > 0 && arr[j] < arr[j - 1])
    {
      int temp = arr[j];
      arr[j] = arr[j - 1];
      arr[j - 1] = temp;
      j--;
    }
  }

  for (int i = 0; i < n; i++)
  {
    printf("%d ", arr[i]);
  }
}