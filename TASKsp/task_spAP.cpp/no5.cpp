#include <stdio.h>

int main()
{
  // int A[3][4] = {1, 3, 2, 4, 5, 7, 6, 8, 9, 11, 12}; // hanya 11 elemen, sisanya jadi 0
  // int B[3][3] = {{1, 2}, {3, 4, 5}, {7}};            // elemen yang tidak diisi otomatis 0

  int A[3][4] = {
      {1, 3, 2, 4},
      {5, 7, 6, 8},
      {9, 11, 12, 0} // 0 default karena hanya 11 nilai, 1 kurang
  };

  int B[3][3] = {
      {1, 2, 0}, // 0 default karena hanya 2 elemen
      {3, 4, 5},
      {7, 0, 0} // sisanya default
  };

  printf("a. A[1][1] = %d\n", A[1][1]); // 7
  printf("b. B[2][2] = %d\n", B[2][2]); // 0
  printf("c. A[2][3] = %d\n", A[2][3]); // 0
  printf("d. B[0][1] = %d\n", B[0][1]); // 2
  printf("e. A[0][2] = %d\n", A[0][2]); // 2

  return 0;
}
