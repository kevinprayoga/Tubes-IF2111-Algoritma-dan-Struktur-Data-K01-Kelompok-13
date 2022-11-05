#include "console.h"

int main()
{
  ArrayDin listgame;
  MakeArrayDin(&listgame);
  char *command = readQ();
  if (compare(command, "QUIT"))
  {

  }
  else
  {
    while (!compare(command, "QUIT"))
    {
      if (compare(command, "START"))
      {
        start(&listgame);
      }
      else if (compare(command, "LOAD"))
      {
        ADVWORD();
        if (currentWord.TabWord[currentWord.Length - 1] != 't' && currentWord.TabWord[currentWord.Length - 2] != 'x' && currentWord.TabWord[currentWord.Length - 3] != 't' && currentWord.TabWord[currentWord.Length - 4] != '.')
        {
          printf("File konfigurasi sistem tidak ditemukan.");
        }
        else
        {
          load(&listgame, currentWord.TabWord);      
        }
      }
      else if (compare(command, "SAVE"))
      {

      }
      else if (compare(command, "CREATE GAME"))
      {

      }
      else if (compare(command, "LIST GAME"))
      {

      }
      else if (compare(command, "DELETE GAME"))
      {

      }
      else if (compare(command, "QUEUE GAME"))
      {

      }
      else if (compare(command, "PLAY GAME"))
      {

      }
      else if (compare(command, "SKIPGAME"))
      {

      }
      else if (compare(command, "QUIT"))
      {

      }
      else if (compare(command, "HELP"))
      {

      }
      else
      {

      }
      char *command = readQ();
    }
  }
  
  if (compare(command, "QUIT"))
  {

  }
  return 0;
}