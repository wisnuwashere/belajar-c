#include <stdio.h>

int main()
{
  int N;
  scanf("%d", &N);

  for (int i = 1; i <= N; i++)
  {

    int hari = i % 7;
    if (hari == 0)
      hari = 7;

    printf("%d ", hari);
  }

  printf("\n");
  return 0;
}
