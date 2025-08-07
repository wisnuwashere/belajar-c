#include <stdio.h>

// Kasus: kalkulator simpel yang menggunakan input dan output sebagai dasar

int main()
{
  float a, b, result;
  char operasi;

  printf("Insert operation (+, -, *, /): ");
  scanf(" %c", &operasi); // spasi sebelum %c untuk menangani newline

  printf("Masukkan dua angka: ");
  scanf("%f %f", &a, &b);

  switch (operasi)
  {
  case '+':
    result = a + b;
    break;
  case '-':
    result = a - b;
    break;
  case '*':
    result = a * b;
    break;
  case '/':
    if (b != 0)
      result = a / b;
    else
    {
      printf("Error: Pembagian dengan nol!\n");
      return 1;
    }
    break;
  default:
    printf("Operasi tidak dikenali.\n");
    return 1;
  }

  printf("Hasil: %.2f\n", result);
  return 0;
}
