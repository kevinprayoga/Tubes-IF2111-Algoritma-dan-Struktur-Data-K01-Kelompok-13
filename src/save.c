#include <stdio.h>
#include <stdlib.h>
#include "save.h"

void save(char *filename, ArrayDin listGame)
{
  FILE *file;
  char path[100] = "../data/";
  while (*filename != '\0')
  {
    path[stringLength(path)] = *filename;
    *filename++;
  }
  file = fopen(path, "w");
  fprintf(file, "%d\n", Length(listGame));
  for (int i = 0; i < Length(listGame) - 1; i++)
  {
    fprintf(file, "%s\n", listGame.A[i]);
  }
  fprintf(file, "%s", listGame.A[Length(listGame) - 1]);
  fclose(file);
  printf("Save file berhasil disimpan.\n");
  fclose(file);
}