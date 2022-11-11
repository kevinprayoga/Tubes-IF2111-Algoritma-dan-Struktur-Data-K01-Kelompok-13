#include <stdio.h>
#include "mesinfile.h"
#include "../function.h"

int main()
{
  FILE *file;
  char path[100] = "../data/config.txt";
  STARTFILE(path);
  CopyWordFile();
  char *strnum = wordToString(currentWord);
  int num = strToInt(strnum);
  if (num != 0)
  {
    ADVFILE();
    printf("Akuisisi dilakukan per kalimat, dan menghasilkan:\n");
    for (int i = 0; i < num; i++)
    {
      ADVWORDFILE();
      char *name = wordToString(currentWord);
      printf("%s\n", name);
    }
  }
  return 0;
}