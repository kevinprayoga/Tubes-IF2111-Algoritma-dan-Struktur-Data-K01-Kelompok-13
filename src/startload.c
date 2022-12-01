#include <stdio.h>
#include <stdlib.h>
#include "startload.h"

void start(ArrayDin *arr)
{
  char path[100] = "../data/config.txt";

  STARTFILE(path);
  CopyWordFile();
  char *strnum = wordToString(currentWord);
  int num = strToInt(strnum);
  if (num > 0)
  {
    ADVFILE();
    for (int i = 0; i < num; i++)
    {
      ADVWORDFILE();
      char *name = wordToString(currentWord);
      InsertLast(arr, name);
    }
    printf("File konfigurasi sistem berhasil dibaca. BNMO berhasil dijalankan.\n");
  }
}

void load(ArrayDin *arr, Stack *s, ListMap *L, char *filename)
{
  char path[100] = "../data/";
  while (*filename != '\0')
  {
    path[stringLength(path)] = *filename;
    *filename++;
  }

  STARTFILE(path);
  ADVWORDFILE();
  char *strnum = wordToString(currentWord);
  int num = strToInt(strnum);
  if (num > 0)
  {
    ADVFILE();
    for (int i = 0; i < num; i++)
    {
      ADVWORDFILE();
      char *name = wordToString(currentWord);
      InsertLast(arr, name);
    }

    ADVFILE();
    ADVWORDFILE();
    char *strnum2 = wordToString(currentWord);
    int num2 = strToInt(strnum2);
    if (num2 > 0)
    {
      ADVFILE();
      Stack s1;
      CreateEmptyStack(&s1);
      info val;
      for (int i = 0; i < num2; i++)
      {
        ADVWORDFILE();
        char *name2 = wordToString(currentWord);
        Push(&s1, name2);
      }
      for (int i = 0; i < num2; i++)
      {
        Pop(&s1, &val);
        Push(s, val);
      }
    }

    int el = 1;
    while (!EndWord)
    {
      CreateEmptyMap(L); 
      ADVFILE();
      ADVWORDFILE();
      char *strnum3 = wordToString(currentWord);
      int num3 = strToInt(strnum3);
      if (num3 > 0)
      {
        ADVFILE();
        for (int i = 0; i < num3; i++)
        {
          ADVWORDFILEWOBLANK();
          char *name3 = wordToString(currentWord);
          ADVWORDFILE();
          char *strscore = wordToString(currentWord);
          int score = strToInt(strscore);
          InsertMap(L, name3, score, el);
        }
      }
      el++;
    }
    printf("Save file berhasil dibaca. BNMO berhasil dijalankan.\n");
  }
  else
  {
    printf("File konfigurasi sistem tidak ditemukan.\n");
  }
}