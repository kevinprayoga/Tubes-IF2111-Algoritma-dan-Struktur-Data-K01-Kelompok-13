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
#include "playgame.h"

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
    if (!initial)
    {
    printf("\nPress ENTER key to back...");
    fgetchar();
    }
  } 
  printf("\nPress ENTER key to continue...");
  fgetchar();
  system("cls");

  while (initial && !final)
  {
    printf("\n==================== M E N U ====================\n");
    printf ("Silahkan pilih perintah yang ingin anda lakukan!\n");
    printf ("\n\t>> LIST GAME\n");
    printf ("\n\t>> QUEUE GAME\n");
    printf ("\n\t>> CREATE GAME\n");
    printf ("\n\t>> DELETE GAME\n");
    printf ("\n\t>> SKIPGAME\n");
    printf ("\n\t>> PLAY GAME\n");
    printf ("\n\t>> SAVE\n");
    printf ("\n\t>> HELP\n");
    printf ("\n\t>> QUIT\n");
    printf("===================================================\n");
    printf("\nENTER COMMAND: ");
    char* command = readQ();
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
        playGame(&q);
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
    if (!final)
    {
      printf("\nPress ENTER key to back...");
      fgetchar();
      system("cls");
    }
  }
  return 0;
}