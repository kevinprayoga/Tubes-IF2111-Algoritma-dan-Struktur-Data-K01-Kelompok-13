#include <stdio.h>
#include <stdlib.h>
#include "startload.h"
#include "coba.h"
#include "save.h"
#include "deletegame.h"
#include "ADT\queue.h"

int main()
{
  ArrayDin listgame;
  listgame = MakeArrayDin();
  Queue q;
  CreateQueue(&q);
  boolean initial = false, final = false;
  while (!initial)
  {
    printf("ENTER COMMAND: ");
    char *command = readQ();
    if (strcompare(command, "START"))
    {
      start(&listgame);
      initial = true;
    }
    else if(strcompare(command, "LOAD"))
    {
      ADVWORD();
      char *filename = wordToString(currentWord);
      if (filename[stringLength(filename) - 1] != 't' && filename[stringLength(filename) - 2] != 'x' && filename[stringLength(filename) - 3] != 't' && filename[stringLength(filename) - 4] != '.')
      {
        printf("File konfigurasi sistem tidak ditemukan.\n");
      }
      else
      {
        load(&listgame, filename);
        initial = true;
      }
    }
    // else
    // {
    //   //command lain
    //   return 0;
    // }
  }

  while (initial && !final)
  {
    printf("\nENTER COMMAND: ");
    char *command = readQ();
    if (strcompare(command, "SAVE"))
    {
      ADVWORD();
      char *filename = wordToString(currentWord);
      save(filename, listgame);
      final = true;
    }
    // else if (strcompare(command, "CREATE GAME"))
    // {
    //   return 0;
    // }
    // else if (strcompare(command, "LIST GAME"))
    // {
    //   return 0;
    // }
    else if (strcompare(command, "DELETE GAME"))
    {
      ADVWORD();
      char *command2 = wordToString(currentWord);
      if (strcompare(command2, "GAME"))
      {
        deleteGame(&listgame, q);
      }
    }
    // else if (strcompare(command, "QUEUE GAME"))
    // {
    //   return 0;
    // }
    // else if (strcompare(command, "PLAY GAME"))
    // {
    //   return 0;
    // }
    // else if (strcompare(command, "SKIPGAME"))
    // {
    //   return 0;
    // }
    // else if (strcompare(command, "HELP"))
    // {
    //   return 0;
    // }
    // else if (strcompare(command, "QUIT"))
    // {
    //   final = true;
    //   return 0;
    // }
    // else
    // {
    //   // run command_lain function
    //   return 0;
    // }
  }
  return 0;
}