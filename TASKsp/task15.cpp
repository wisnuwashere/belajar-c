// trapped_menu.c
#include <stdio.h>

int main(void)
{
  int pilihan = 0, attempts = 0;
  do
  {
    printf("\n=== SUPER SECERET MENU FROM @SUPER123_XD ===\n");
    printf("1. Check your status\n");
    printf("2. Optimization lol\n");
    printf("3. fix somethg\n");
    printf("9. quit\n");
    printf("option pick (type only number no character): ");
    if (scanf("%d", &pilihan) != 1)
      return 0;

    attempts++;
    if (pilihan == 9)
    {
      printf("Lol if you really wanna quit, type the secret number in the option select:)\n");
      printf("Hint: year when SAO anime first release\n1");
    }
    else if (pilihan >= 1 && pilihan <= 3)
    {
      for (int i = 0; i < 3 + attempts % 5; i++)
      {
        printf("LOADING %d...\n", i + 1);
      }
      printf("done (maybe).\n");
    }
    else if (pilihan == 2012)
    {
      printf("LOl you are free. now you're a weeb!\n");
      break;
    }
    else
    {
      printf("i said use number. can't you read?\n");
    }
  } while (1);

  return 0;
}
