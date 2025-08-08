#include <stdio.h>

int main()
{
  int A[4][5] = {
      {3, 4, 5, 5, 0},
      {5, 6, 7, 9, 0},
      {1, 7, 11, 10, 0},
      {2, 8, 9, 4, 0}};

  int B[4][5] = {
      {1, 2, 3, 4, 0},
      {8, 7, 6, 5, 0},
      {9, 10, 11, 2, 0},
      {6, 5, 4, 3, 0}};

  int C[4][5];

  printf("Hasil Penjumlahan Matriks:\n");
  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 5; j++)
    {
      C[i][j] = A[i][j] + B[i][j];
      printf("%4d", C[i][j]);
    }
    printf("\n");
  }

  return 0;
}
