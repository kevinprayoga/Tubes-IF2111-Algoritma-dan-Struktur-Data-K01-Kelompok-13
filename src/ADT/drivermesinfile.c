#include <stdio.h>
#include "mesinfile.h"
#include "../function.h"

int main()
{
  char path[100] = "../../data/savefile.txt";

  STARTFILE(path);
  ADVWORDFILE();
  char *strnum = wordToString(currentWord);
  int num = strToInt(strnum);
  printf("%d\n", num);
  if (num > 0)
  {
    ADVFILE();
    for (int i = 0; i < num; i++)
    {
      ADVWORDFILE();
      char *name = wordToString(currentWord);
      printf("%s\n", name);
    }

    ADVFILE();
    ADVWORDFILE();
    char *strnum2 = wordToString(currentWord);
    int num2 = strToInt(strnum2);
    printf("%d\n", num2);
    if (num2 > 0)
    {
      ADVFILE();
      for (int i = 0; i < num2; i++)
      {
        ADVWORDFILE();
        char *name2 = wordToString(currentWord);
        printf("%s\n", name2);
      }
    }

    while (!EndWord)
    {
      ADVFILE();
      ADVWORDFILE();
      char *strnum3 = wordToString(currentWord);
      int num3 = strToInt(strnum3);
      printf("%d\n", num3);
      if (num3 > 0)
      {
        ADVFILE();
        for (int i = 0; i < num3; i++)
        {
          ADVWORDFILEWOBLANK();
          char *name3 = wordToString(currentWord);
          printf("%s ", name3);
          ADVWORDFILE();
          char *strscore = wordToString(currentWord);
          int score = strToInt(strscore);
          printf("%d\n", score);
        }
      }
    }
    printf("File konfigurasi sistem berhasil dibaca. BNMO berhasil dijalankan.\n");
  }
  else
  {
    printf("File konfigurasi sistem tidak ditemukan.\n");
  }
  return 0;
}