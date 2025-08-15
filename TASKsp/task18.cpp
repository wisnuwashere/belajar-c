#include <stdio.h>

// iterative
int faktorial_iter(int num)
{
  int answer = 1;
  for (int i = 1; i <= num; i++)
  {
    answer *= i;
  }
  return answer;
}

// rekurif
int faktorial_rec(int num)
{
  if (num == 0 || num == 1)
    return 1;
  return num * faktorial_rec(num - 1);
}

// main module
int main()
{
  int num;

  printf("Masukkan angka: ");
  scanf("%d", &num);

  printf("\nIterative \n");
  printf("Faktorial dari %d = %d\n", num, faktorial_iter(num));

  printf("\nRecursive \n");
  printf("Faktorial dari %d = %d\n", num, faktorial_rec(num));

  return 0;
}
