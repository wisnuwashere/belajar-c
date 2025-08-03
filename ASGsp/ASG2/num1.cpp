#include <stdio.h>

int PrimeRecursive(int x, int pembagi)
{
  if (pembagi == 1)
    return 1;
  if (x % pembagi == 0)
    return 0;
  return PrimeRecursive(x, pembagi - 1);
}

int isPrime(int x)
{
  if (x <= 1)
    return 0;
  return PrimeRecursive(x, x - 1);
}

int main()
{
  int T;
  scanf("%d", &T);

  for (int i = 1; i <= T; i++)
  {
    int x;
    scanf("%d", &x);

    if (isPrime(x))
      printf("Case #%d: Prime Number\n", i);
    else
      printf("Case #%d: Not Prime Number\n", i);
  }

  return 0;
}
