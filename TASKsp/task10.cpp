#include <stdio.h>

int main()
{
  int N;

  printf("== Streaming Video Pembelajaran Online - SOCS BINUS ==\n");
  printf("Pilih salah satu streaming berikut:\n");
  printf("1. Software Engineering\n");
  printf("2. Intelligence System\n");
  printf("3. Network Technology\n");
  printf("4. Database Technology\n");
  printf("5. Interactive Multimedia\n");
  printf("Masukkan pilihan Anda (1-5): ");
  scanf("%d", &N);

  printf("\nAnda memilih: ");
  switch (N)
  {
  case 1:
    printf("Software Engineering\n");
    break;
  case 2:
    printf("Intelligence System\n");
    break;
  case 3:
    printf("Network Technology\n");
    break;
  case 4:
    printf("Database Technology\n");
    break;
  case 5:
    printf("Interactive Multimedia\n");
    break;
  default:
    printf("Pilihan tidak valid. Silakan masukkan angka 1-5.\n");
  }

  return 0;
}
