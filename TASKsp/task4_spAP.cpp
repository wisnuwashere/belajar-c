#include <stdio.h>

int main()
{
  int assignment, mid, finale;
  scanf("%d %d %d", &assignment, &mid, &finale);

  int finalScore = 0.2 * assignment + 0.3 * mid + 0.5 * finale;

  printf("%d\n", finalScore);

  return 0;
}