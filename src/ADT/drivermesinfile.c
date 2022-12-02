#include <stdio.h>
#include "mesinfile.h"
#include "../console.h"

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
    }

    ADVFILE();
    ADVWORDFILE();
    char *strnum2 = wordToString(currentWord);
    int num2 = strToInt(strnum2);
    if (num2 > 0)
    {
      ADVFILE();
      for (int i = 0; i < num2; i++)
      {
        ADVWORDFILE();
        char *name2 = wordToString(currentWord);
      }
    }

    int el = 1;
    while (!EndWord)
    {
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
        }
      }
      el++;
    }
    printf("Save file berhasil dibaca. BNMO berhasil dijalankan.\n");
  }
  else
  {
    printf("Save file tidak ditemukan.\n");
  }
  return 0;
}