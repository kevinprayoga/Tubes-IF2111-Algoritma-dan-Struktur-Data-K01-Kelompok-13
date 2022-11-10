#include <stdio.h>
#include <stdlib.h>
#include "startload.h"
#include "function.h"
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
#include "asciiart.h"

int main()
{
  welcompage();
  printf ("Selamat datang di BNMO!\n");
  printf ("Silahkan pilih perintah yang ingin anda lakukan!\n");
  printf ("\n\t>> START\n");
  printf ("\n\t>> LOAD\n");
  ArrayDin listgame;
  listgame = MakeArrayDin();
  Queue q;
  CreateQueue(&q);
  boolean initial = false, final = false;
  char* command;
  while (!initial)
  {
    printf("\nENTER COMMAND: ");
    command = readQ();
    if (space_char(command) == 0)
    {
      if (strcompare(command, "START"))
      {
        start(&listgame);
        initial = true;
      }
      else
      {
        commandLain();
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
        commandLain();
      }
    }
    else
    {
      commandLain();
    }
    printf("\nPress ENTER key to continue...");
    fgetchar();
    system("cls");
  } 

  while (initial && !final)
  {
    printf("\n========== M E N U ==========\n");
    printf("\nENTER COMMAND: ");
    STARTWORD();
    char* command = wordToString(currentWord);
    if (space_char(command) > 1)
    {
      commandLain();
    }
    else
    {
      if (strcompare(command, "CREATE GAME"))
      {
        createGame(&listgame);
        printf("\nPress ENTER key to back...");
        fgetchar();
      }
      else if (strcompare(command, "LIST GAME"))
      {
        ListGame(&listgame);
        printf("\nPress ENTER key to back...");
        fgetchar();
      }
      else if (strcompare(command, "DELETE GAME"))
      {
        deleteGame(&listgame, q);
        printf("\nPress ENTER key to back...");
        fgetchar();
      }
      else if (strcompare(command, "QUEUE GAME"))
      {
        QueueGame(&q, listgame);
        printf("\nPress ENTER key to back...");
        fgetchar();
      }
      else if (strcompare(command, "PLAY GAME"))
      {
        //play game
      }
      else if (strcompare(command, "HELP"))
      {
        help();
        printf("\nPress ENTER key to back...");
        fgetchar();
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
          printf("\nPress ENTER key to back...");
          fgetchar();
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
            printf("\nPress ENTER key to back...");
            fgetchar();
          }
        }
        else
        {
          commandLain();
          printf("\nPress ENTER key to back...");
          fgetchar();
        }
      }
      else
      {
        commandLain();
        printf("\nPress ENTER key to back...");
        fgetchar();
      }
    }
    if (!final)
    {
      system("cls");
    }
  }
  return 0;
}