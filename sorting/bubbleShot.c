#include <stdio.h>
#include <stdbool.h>
int main()
{
  int n;
  printf("how many element you want in array :");
  scanf("%d", &n);

  int arr[n];

  for (int i = 0; i < n; i++)
  {
    printf("Enter %d element :", i + 1);
    scanf("%d", &arr[i]);
  }

  for (int i = 0; i < n - 1; i++)
  {
    bool flag = true;
    for (int j = 0; j < n - 1 - i; j++)
    {

      if (arr[j] > arr[j + 1])
      {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
        flag = false;
      }
    }
    if (flag == true)
      break;
  }
  for (int i = 0; i < n; i++)
  {
    printf("%d ", arr[i]);
  }
}
