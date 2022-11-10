#include <stdio.h>
#include <stdlib.h>
#include "startload.h"
#include "coba.h"
#include "save.h"
#include "ADT\queue.h"
#include "ADT\mesinkata.h"
#include "ADT\mesinkar.h"
#include "ADT\arraydin.h"
#include "ADT\mesinfile.h"
#include "commandlain.h"
#include "creategame.h"
#include "deletegame.h"
#include "help.h"
#include "listgame.h"
#include "queuegame.h"
#include "quit.h"
#include "save.h"
#include "skipgame.h"

int main()
{
  ArrayDin listgame;
  listgame = MakeArrayDin();
  Queue q;
  CreateQueue(&q);
  boolean initial = false, final = false;
  char* command;
  while (!initial)
  {
    printf("ENTER COMMAND: ");
    command = readQ();
    if (space_char(command) == 0)
    {
      if (strcompare(command, "START"))
      {
        start(&listgame);
        printf("testing\n");
        initial = true;
      }
      else
      {
        //command lain
      }
    }
    else if (space_char(command) == 1)
    {
      char *string_first = firststring(command);
      char *string_second = secondstring(command);
      if (strcompare(string_first, "LOAD"))
      {
        load(&listgame, string_second);
        if (!IsEmpty(listgame))
        {
          initial = true;
        }
      }
      else
      {
        //command lain
      }
    }
    else
    {
      // command lain
    }
  } 

  while (initial && !final)
  {
    printf("\n=====MENU=====\n");
    printf("\nENTER COMMAND: ");
    STARTWORD();
    char* command = wordToString(currentWord);
    printf("tes menu\n");
    if (space_char(command) > 1)
    {
      commandLain();
    }
    else
    {
      if (strcompare(command, "CREATE GAME"))
      {
        createGame(&listgame);
      }
      else if (strcompare(command, "LIST GAME"))
      {
        ListGame(&listgame);
      }
      else if (strcompare(command, "DELETE GAME"))
      {
        deleteGame(&listgame, q);
      }
      else if (strcompare(command, "QUEUE GAME"))
      {
        QueueGame(&q, listgame);
      }
      else if (strcompare(command, "PLAY GAME"))
      {
        //play game
      }
      else if (strcompare(command, "HELP"))
      {
        help();
      }
      else if (strcompare(command, "QUIT"))
      {
        Quit(listgame);
        final = true;
      }
      else if (space_char(command) == 1)
      {
        char *string_first = firststring(command);
        char *string_second = secondstring(command);
        if (strcompare(string_first, "SAVE"))
        {
          save(string_second, listgame);
        }
        else if (strcompare(string_first, "SKIPGAME"))
        {
          if (isNum(string_second))
          {
            SkipGame(&q, strToInt(string_second));
            printf("Game berhasil di-SKIP\n");
          }
          else
          {
            commandLain();
          }
        }
        else
        {
          commandLain();
        }
      }
      else
      {
        commandLain();
      }
    }
  }
  return 0;
}