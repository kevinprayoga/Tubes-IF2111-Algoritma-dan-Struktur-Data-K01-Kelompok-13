#include <stdio.h>
#include <stdlib.h>
// #include "startload.h"
// #include "function.h"
// #include "save.h"
// #include "ADT\queue.h"
// #include "ADT\mesinkata.h"
// #include "ADT\mesinkar.h"
// #include "ADT\arraydin.h"
// #include "ADT\mesinfile.h"
// #include "commandlain.h"
// #include "creategame.h"
// #include "deletegame.h"
// #include "help.h"
// #include "listgame.h"
// #include "queuegame.h"
// #include "quit.h"
// #include "save.h"
// #include "skipgame.h"
// #include "asciiart.h"
// #include "playgame.h"
// #include "dinerdash.h"
// #include "gameRNG.h"
// #include "minesweeper.h"
// #include "ADT\stack.h"
// #include "history.h"
// #include "ADT\listofmap.h"
// #include "scoreboard.h"
// #include "resethistory.h"
// #include "resetscoreboard.h"
// #include "ADT\stackTOH.h"
// #include "towerofhanoi.h"
#include "console.h"

int main()
{
  welcompage();
  printf("Selamat datang di BNMO!\n");
  printf("Silahkan pilih perintah yang ingin anda lakukan!\n");
  printf("\n\t>> START\n");
  printf("\n\t>> LOAD\n");
  ArrayDin listgame;
  listgame = MakeArrayDin();
  Queue q;
  CreateQueue(&q);
  Stack hist;
  CreateEmptyStack(&hist);
  ListMap listscoreboard;
  CreateEmptyListMap(&listscoreboard);
  boolean initial = false, final = false;
  char *command;
  while (!initial)
  {
    printf("\nENTER COMMAND: ");
    command = readQ();
    if (space_char(command) == 0)
    {
      if (strcompare(command, "START"))
      {
        start(&listgame);
        for (int i = 0; i < listgame.Neff; i++)
        {
          CreateEmptyMap(&listscoreboard);
        }
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
        load(&listgame, &hist, &listscoreboard, string_second);
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
    printf("Silahkan pilih perintah yang ingin anda lakukan!\n");
    printf("\n\t>> LIST GAME\n");
    printf("\n\t>> QUEUE GAME\n");
    printf("\n\t>> CREATE GAME\n");
    printf("\n\t>> DELETE GAME\n");
    printf("\n\t>> SKIP GAME <n>\n");
    printf("\n\t>> PLAY GAME\n");
    printf("\n\t>> SCOREBOARD\n");
    printf("\n\t>> RESET SCOREBOARD\n");
    printf("\n\t>> HISTORY <n>\n");
    printf("\n\t>> RESET HISTORY\n");
    printf("\n\t>> SAVE <filename>\n");
    printf("\n\t>> HELP\n");
    printf("\n\t>> QUIT\n");
    printf("===================================================\n");
    printf("\nENTER COMMAND: ");
    command = readQ();
    if (space_char(command) > 2)
    {
      commandLain();
    }
    else
    {
      if (strcompare(command, "CREATE GAME"))
      {
        createGame(&listgame, &listscoreboard);
      }
      else if (strcompare(command, "LIST GAME"))
      {
        ListGame(&listgame);
      }
      else if (strcompare(command, "DELETE GAME"))
      {
        deleteGame(&listgame, &hist, &listscoreboard, q);
      }
      else if (strcompare(command, "QUEUE GAME"))
      {
        QueueGame(&q, listgame);
      }
      else if (strcompare(command, "PLAY GAME"))
      {
        playGame(&q, &hist, &listscoreboard, listgame);
      }
      else if (strcompare(command, "SCOREBOARD"))
      {
        scoreboard(listscoreboard, listgame);
      }
      else if (strcompare(command, "RESET SCOREBOARD"))
      {
        resetscoreboard(&listscoreboard, listgame);
      }
      else if (strcompare(command, "RESET HISTORY"))
      {
        resetHistory(&hist);
      }
      else if (strcompare(command, "HELP"))
      {
        help();
      }
      else if (strcompare(command, "QUIT"))
      {
        Quit(listgame, hist, listscoreboard);
        fgetchar();
        final = true;
      }
      else if (space_char(command) == 1)
      {
        char *string_first = firststring(command);
        char *string_second = secondstring(command);
        if (strcompare(string_first, "SAVE"))
        {
          save(string_second, listgame, hist, listscoreboard);
        }
        else if (strcompare(string_first, "HISTORY"))
        {
          if (isNum(string_second))
          {
            history(&hist, strToInt(string_second));
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
      else if (space_char(command) == 2)
      {
        char *string_first = firststring(command);
        char *string_second = secondstring(command);
        char *string_third = thirdstring(command);
        if (strcompare(string_first, "SKIP") && strcompare(string_second, "GAME"))
        {
          if (isNum(string_third))
          {
            SkipGame(&q, hist, listscoreboard, listgame, strToInt(string_third));
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
  exit(0);
  return 0;
}