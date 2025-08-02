#include <stdio.h>

int main()
{
  int n;
  for (;;)
  {
    printf("\n Enter integer : ");
    scanf("%d", &n);
    if ((n % 2) == 0)
      continue;
    else if ((n % 3) == 0)
      break;
    printf("\n\t Bottom of loop.");
  }
  printf("\n\t Outside of loop.");
}

/*
  answer:
  -> input 7 = tidak ada kelipatan dua maupun tiga jadi akan mengprint "Bottom of loop." lalu mengulang loop karena for(; ;)
  -> input 4 = kelipatan dua jadi akan mengulang loop dari awal karena continue
  -> input 9 = kelipatan tiga jadi akan break dan mengprint "Outside of loop."
*/