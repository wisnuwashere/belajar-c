#include <stdio.h>
#include <string.h>

int main()
{
  FILE *file = fopen("testdata2.in", "r");
  if (file == NULL)
  {
    printf("File not found!\n");
    return 1;
  }
  int T;
  fscanf(file, "%d\n", &T);

  for (int t = 1; t <= T; t++)
  {
    int N;
    fscanf(file, "%d\n", &N);

    char names[105][35];
    for (int i = 0; i < N; i++)
    {
      fgets(names[i], 35, file);
      names[i][strcspn(names[i], "\n")] = 0; // hapus neww line
    }

    char target[35];
    fgets(target, 35, file);
    target[strcspn(target, "\n")] = 0;

    int found = 0;
    for (int i = 0; i < N; i++)
    {
      if (strcmp(names[i], target) == 0)
      {
        printf("Case #%d: %d\n", t, i + 1);
        found = 1;
        break;
      }
    }

    if (!found)
    {
      printf("Case #%d: Not found\n", t);
    }
  }

  fclose(file);
  return 0;
}
