#include <stdio.h>
#include <stdlib.h>
#include "startload.h"

void start(ArrayDin *arr)
{
  load(arr, "config.txt");
}

void load(ArrayDin *arr, char *filename)
{
  FILE *file;
  char path[100] = "../data/";
  while (*filename != '\0')
  {
    path[stringLength(path)] = *filename;
    *filename++;
  }
  STARTFILE(path);
  CopyWordFile();
  if (path != NULL)
  {
    char *strnum = wordToString(currentWord);
    int num = strToInt(strnum);
    ADVFILE();
    for (int i = 0; i < num; i++)
    {
      ADVWORDFILE();
      char *name = wordToString(currentWord);
      InsertLast(arr, name);
    }
    printf("File konfigurasi sistem berhasil dibaca. BNMO berhasil dijalankan.\n");
  }
  else
  {
    printf("File konfigurasi sistem tidak ditemukan.\n");
  }
}