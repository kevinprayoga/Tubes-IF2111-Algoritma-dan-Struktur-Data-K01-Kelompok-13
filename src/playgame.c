#include <stdio.h>
#include <stdlib.h>
#include "playgame.h"

void playGame(Queue *q)
{
  ElType val;
  printf("\nBerikut adalah daftar antrian Game-mu\n");
  if (isEmpty(*q))
  {
    displayQueue(*q);
  }
  else
  {
    displayQueue(*q);
    dequeue(q, &val);
    if (strcompare(val, "RNG"))
    {
      printf("Loading %s ...\n", val);
      //mulai game rng
    }
    else if (strcompare(val, "Diner DASH"))
    {
      printf("Loading %s ...\n", val);
      //mulai game diner dash
    }
    else if (strcompare(val, "Minesweeper"))
    {
      printf("Loading %s ...\n", val);
      //mulai game minesweeper
    }
    else
    {
      printf("\nGame %s masih dalam maintenance, belum dapat dimainkan.\nSilahkan pilih game lain.\n", val);
    }
  }
}