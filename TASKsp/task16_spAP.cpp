#include <stdio.h>

int main()
{
  char ans;
  int fact = 0;

  printf("5 Facts About Me\n");

  printf("1. What's my fav ani?\n");
  printf("a. K-On\n");
  printf("b. Clannad\n");
  printf("c. Love Live Sunshine\n");
  printf("Jawaban: ");
  scanf(" %c", &ans);

  if (ans == 'b' || ans == 'B')
  {
    printf("clannad peak.\n");
    fact++;
  }
  else
  {
    printf("Wrong lol\n");
  }

  // Soal 2
  printf("\n2. Coffee or Tea?\n");
  printf("a. Coffee\n");
  printf("b. Tea\n");
  printf("Jawaban: ");
  scanf(" %c", &ans);

  if (ans == 'a' || ans == 'A')
  {
    printf("YES COFFEE IS BETTER!!\n");
    fact++;
  }
  else
  {
    printf("why? tea is bland and lame\n");
  }

  // Soal 3
  printf("\n3. What is my favorite season?\n");
  printf("a. Spring\n");
  printf("b. Summer\n");
  printf("c. Winter\n");
  printf("Jawaban: ");
  scanf(" %c", &ans);

  if (ans == 'c' || ans == 'C')
  {
    printf("right. although i never feel winter myself. but winter souns cool.\n");
    fact++;
  }
  else
  {
    printf("BOopop wrong\n");
  }

  // Soal 4
  printf("\n4. Which one do I prefer?\n");
  printf("a. Rice\n");
  printf("b. Bread\n");
  printf("Jawaban: ");
  scanf(" %c", &ans);

  if (ans == 'a' || ans == 'A')
  {
    printf("YES! FINALLY SOMEONE UNDERSTAND\n");
    fact++;
  }
  else
  {
    printf("WHY!? RICE IS BLAND AND MUSHY\n");
  }

  // Soal 5
  printf("\n5. My favorite J-Pop song?\n");
  printf("a. New Genesis\n");
  printf("b. Takane no Hanakosan\n");
  printf("c. Cat Loving\n");
  printf("Jawaban: ");
  scanf(" %c", &ans);

  if (ans == 'b' || ans == 'B')
  {
    printf("you got a taste\n");
    fact++;
  }
  else
  {
    printf("mid taste lol\n");
  }

  // Hasil akhir
  printf("\n QUIZ OVER \n");
  printf("Kamu tahu %d/5 facts about me\n", fact);

  return 0;
}
