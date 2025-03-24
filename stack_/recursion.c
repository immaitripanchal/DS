#include <stdio.h>
int factorial(int n);
void main()
{
  int n;
  printf("Enter any number :");
  scanf("%d", &n);
  int answer = factorial(n);
  printf("Factorial of %d is %d ", n, answer);
}
int factorial(int n)
{
  if (n == 1)
  {
    return 1;
  }
  return n * factorial(n - 1);
}