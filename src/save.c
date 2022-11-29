#include <stdio.h>
#include <stdlib.h>
#include "save.h"

void save(char *filename, ArrayDin listGame, Stack s, ListMap L)
{
  FILE *file;
  char path[100] = "../data/";
  while (*filename != '\0')
  {
    path[stringLength(path)] = *filename;
    *filename++;
  }
  file = fopen(path, "w");

  // baca listgame
  fprintf(file, "%d\n", Length(listGame));
  for (int i = 0; i < Length(listGame); i++)
  {
    fprintf(file, "%s\n", listGame.A[i]);
  }

  // baca history
  fprintf(file, "%d\n", countStack(s));
  for (int i = countStack(s) - 1; i >= 0; i--)
  {
    fprintf(file, "%s\n", s.T[i]);
  }

  // baca scoreboard
  for (int i = 0; i < L.total - 1; i++)
  {
    fprintf(file, "%d\n", L.list[i].Count);
    if (L.list[i].Count >  0)
    {
      for (int j = 0; j < L.list[i].Count; j++)
      {
        fprintf(file, "%s %d\n", L.list[i].Elements[j].Key, L.list[i].Elements[j].Value);
      }
    }
  }
  if (L.list[L.total - 1].Count > 0)
  {
    fprintf(file, "%d\n", L.list[L.total - 1].Count);
    for (int j = 0; j < L.list[L.total - 1].Count - 1; j++)
    {
      fprintf(file, "%s %d\n", L.list[L.total - 1].Elements[j].Key, L.list[L.total - 1].Elements[j].Value);
    }
    fprintf(file, "%s %d", L.list[L.total - 1].Elements[L.list[L.total - 1].Count - 1].Key, L.list[L.total - 1].Elements[L.list[L.total - 1].Count - 1].Value);
  }
  else
  {
    fprintf(file, "%d", L.list[L.total - 1].Count);
  }

  fclose(file);
  printf("Save file berhasil disimpan.\n");
  fclose(file);
}