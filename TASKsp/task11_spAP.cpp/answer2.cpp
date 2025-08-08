#include <stdio.h>

int main()
{
  float ipk;
  printf("Masukkan IPK: ");
  scanf("%f", &ipk);

  if (ipk >= 3.5 && ipk <= 4.0)
    printf("Cumlaude\n");
  else if (ipk >= 3.0)
    printf("Outstanding\n");
  else if (ipk >= 2.5)
    printf("Very Good\n");
  else if (ipk >= 2.0)
    printf("Good\n");
  else
    printf("Poor\n");

  return 0;
}
