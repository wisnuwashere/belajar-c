#include <stdio.h>

int main()
{
  char lulus;
  char tindakan[100][100];
  int count = 0;

  printf("Are you already graduated this year? ");
  scanf(" %c", &lulus);

  while (lulus != 'y' && lulus != 'Y') // im using while lol
  {
    printf("What things would you do to graduate?\n");
    scanf(" %[^\n]", tindakan[count]);
    count++;

    printf("Are you already graduated this year? ");
    scanf(" %c", &lulus);
  }
  printf("\nThings you did to graduate right now:\n");
  for (int i = 0; i < count; i++)
  {
    printf("- %s\n", tindakan[i]);
  }

  printf("\nSelamat, kamu telah lulus MK ini!\n");

  return 0;
}