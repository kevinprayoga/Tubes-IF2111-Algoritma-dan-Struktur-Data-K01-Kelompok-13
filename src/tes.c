#include <stdio.h>
#include "startload.h"

int main()
{
  ArrayDin listgame;
  listgame = MakeArrayDin();
  char *command = readQ();
  char *string_first = firststring(command);
  if (strcompare(command, "START"))
  {
    start(&listgame);
  }
  else if(strcompare(command, "LOAD"))
  {
    char *filename = wordToString(currentWord);
    if (filename[stringLength(filename) - 1] != 't' && filename[stringLength(filename) - 2] != 'x' && filename[stringLength(filename) - 3] != 't' && filename[stringLength(filename) - 4] != '.')
    {
      printf("File konfigurasi sistem tidak ditemukan.\n");
    }
    else
    {
      load(&listgame, filename);
    }
  }
  return 0;
}