#include <stdio.h>
#include <stdlib.h>
#include "startload.h"
#include "coba.h"
#include "save.h"
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
    if (space_char(command) == 0)
    {
      if (strcompare(command, "START"))
      {
        start(&listgame);
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
    printf("\nENTER COMMAND: ");
    char *command = readQ();
    if (space_char(command) > 1)
    {
      //command lain
    }
    else
    {
      if (strcompare(command, "CREATE GAME"))
      {
        //create game 
      }
      else if (strcompare(command, "LIST GAME"))
      {
        //list game
      }
      else if (strcompare(command, "DELETE GAME"))
      {
        //delete game
      }
      else if (strcompare(command, "QUEUE GAME"))
      {
        //queue game
      }
      else if (strcompare(command, "PLAY GAME"))
      {
        //play game
      }
      else if (strcompare(command, "HELP"))
      {
        //help
      }
      else if (strcompare(command, "QUIT"))
      {
        //quit
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
          //ubah string ke integer
          //skipgame
        }
        else
        {
          //command lain
        }
      }
      else
      {
        //command lain
      }
    }
  }
  return 0;
}