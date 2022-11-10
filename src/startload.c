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
  int num = currentChar - '0';
  if (num != -38)
  {
    ADVFILE();
    printf("testing\n");
    for (int i = 0; i < num; i++)
    {
      ADVWORDFILE();
      char *name = wordToString(currentWord);
      printf("%s\n", name);
      InsertAt(arr, name, i);
    }
    printf("File konfigurasi sistem berhasil dibaca. BNMO berhasil dijalankan.\n");
  }
  else
  {
    printf("File konfigurasi sistem tidak ditemukan.\n");
  }
}