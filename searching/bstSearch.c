#include <stdio.h>
#include <stdbool.h>
int search(int arr[], int key, int n);
void sort(int arr[], int n);
int main()
{
  int n;
  printf("Enter how many element you want in array : ");
  scanf("%d", &n);

  int arr[n];

  for (int i = 0; i < n; i++)
  {
    printf("Enter element %d :", i + 1);
    scanf("%d", &arr[i]);
  }

  int key;
  printf("Enter value you want to search :");
  scanf("%d", &key);

  sort(arr, n);
  printf("sorted array :\n");
  for (int i = 0; i < n; i++)
  {
    printf("%d ", arr[i]);
  }
  int result = search(arr, key, n);
  if (result != -1)
  {
    printf("Element found at %d position", result + 1);
  }
  else
  {
    printf("Element not found:\n");
  }
}
int search(int arr[], int key, int n)
{
  int left = 0, right = n - 1;
  while (left <= right)
  {
    int mid = left + (right - left) / 2;
    if (arr[mid] == key)
    {
      return mid;
    }
    if (arr[mid] < key)
    {
      left = mid + 1;
    }
    if (arr[mid] > key)
    {
      right = mid - 1;
    }
  }
  return -1;
}
void sort(int arr[], int n)
{
  for (int i = 0; i < n - 1; i++)
  {
    bool flag = false;
    for (int j = 0; j < n - 1 - i; j++)
    {
      if (arr[j] > arr[j + 1])
      {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
        flag = true;
      }
    }
    if (flag == false)
      break;
  }
}