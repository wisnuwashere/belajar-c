#include <stdio.h>

int main()
{
  int num[10];
  int i, max, min, sum = 0;
  float rata2;

  printf("Masukkan 10 angka: ");
  for (i = 0; i < 10; i++)
  {
    printf("Angka ke-%d: ", i + 1);
    scanf("%d", &num[i]);
    sum += num[i];
  }

  max = min = num[0];
  for (i = 1; i < 10; i++)
  {
    if (num[i] > max)
      max = num[i];
    if (num[i] < min)
      min = num[i];
  }

  rata2 = sum / 10.0;

  printf("\nHasil:\n");
  printf("Nilai maksimum: %d\n", max);
  printf("Nilai minimum: %d\n", min);
  printf("Rata-rata: %.2f\n", rata2);

  return 0;
}
