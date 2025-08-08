#include <stdio.h>

int main()
{
  int i;

  // Menggunakan for
  for (i = 11; i <= 188; i += 2)
  {
    printf("%d ", i);
  }

  printf("\n");

  // Menggunakan while
  i = 11;
  while (i <= 188)
  {
    printf("%d ", i);
    i += 2;
  }

  printf("\n");

  // Menggunakan do-while
  i = 11;
  do
  {
    printf("%d ", i);
    i += 2;
  } while (i <= 188);

  return 0;
}