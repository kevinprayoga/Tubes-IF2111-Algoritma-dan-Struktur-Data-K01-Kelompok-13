#include <stdio.h>
#include <stdlib.h>
#include "playgame.h"
#include "ADT/stack.h"

void playGame(Queue *q, Stack *s)
{

  ElType val;
  printf("\nBerikut adalah daftar antrian Game-mu :\n");
  if (isEmpty(*q))
  {
    displayQueue(*q);
  }
  else
  {
    displayQueue(*q);
    dequeue(q, &val);
    Push(&s, val);
    if (strcompare(val, "RNG") || strcompare(val, "Diner DASH") || strcompare(val, "Minesweeper"))
    {
      printf("Loading %s ...\n", val);
      printf("\nPress ENTER key to play %s...", val);
      fgetchar();
      system("cls");
      if (strcompare(val, "RNG"))
      {
        rng();
      }
      else if (strcompare(val, "Diner DASH"))
      {
        dinerdash();
        // mulai game diner dash
      }
      else if (strcompare(val, "Minesweeper"))
      {
        playmine();
        // mulai game minesweeper
      }
    }
    else if (strcompare(val, "DINOSAUR IN EARTH") || strcompare(val, "RISEWOMAN") || strcompare(val, "EIFFEL TOWER"))
    {
      printf("\nGame %s masih dalam maintenance, belum dapat dimainkan.\nSilahkan pilih game lain.\n", val);
    }
    else
    {
      printf("\n\nLoading %s ...\n", val);
      printf("\nPress ENTER key to play %s...", val);
      fgetchar();
      system("cls");
      customGame();
    }
  }
}