#include <stdio.h>
#include "startload.h"

void start(ArrayDin *arr)
{
  load(arr, "config.txt");
}

void load(ArrayDin *arr, char *filename)
{
  FILE *file;
  char path[100] = "data/";
  while (*filename != '\0')
  {
    path[stringLength(path)] = *filename;
    *filename++;
  }
  file = fopen(path, "r");
  if (file == NULL)
  {
    printf("File konfigurasi sistem tidak ditemukan.\n");
  }
  else
  {
    STARTSENTENCE();
    int num = sentenceToInt(currentSentence);
    printf("%d\n", num);
    for (int i = 0; i < num; i++)
    {
      ADVSENTENCE();
      char *name = sentenceToString(currentSentence);
      printf("%s\n", name);
      InsertAt(arr, name, i);
    }
    printf("File konfigurasi sistem berhasil dibaca. BNMO berhasil dijalankan.\n");
  }
}