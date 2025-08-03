#include <stdio.h>
#include <stdlib.h>

struct Answer
{
  int num;
  char answer;
};

int compare(const void *a, const void *b)
{
  return ((struct Answer *)a)->num - ((struct Answer *)b)->num;
}

int main()
{
  FILE *file = fopen("testdata.in", "r");
  if (file == NULL)
  {
    printf("File not found!\n");
    return 1;
  }
  int T;
  fscanf(file, "%d", &T);

  for (int t = 1; t <= T; t++)
  {
    int N;
    fscanf(file, "%d", &N);

    struct Answer data[105];

    for (int i = 0; i < N; i++)
    {
      fscanf(file, "%d. %c", &data[i].num, &data[i].answer);
    }

    qsort(data, N, sizeof(struct Answer), compare);

    printf("Case #%d:\n", t);
    for (int i = 0; i < N; i++)
    {
      printf("%d. %c\n", data[i].num, data[i].answer);
    }
  }

  fclose(file);
  return 0;
}
