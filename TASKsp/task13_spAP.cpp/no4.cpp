#include <stdio.h>

int main()
{
  int A[4][5] = {
      {3, 4, 5, 5, 0},
      {5, 6, 7, 9, 0},
      {1, 7, 11, 10, 0},
      {2, 8, 9, 4, 0}};

  int B[5][4] = {
      {1, 2, 3, 4},
      {8, 7, 6, 5},
      {9, 10, 11, 2},
      {6, 5, 4, 3},
      {0, 0, 0, 0} // baris kelima agar ukuran valid (5*4)
  };

  int C[4][4] = {0};

  printf("Hasil Perkalian Matriks:\n");
  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 4; j++)
    {
      for (int k = 0; k < 5; k++)
      {
        C[i][j] += A[i][k] * B[k][j];
      }
      printf("%6d", C[i][j]);
    }
    printf("\n");
  }

  return 0;
}
