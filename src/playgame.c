#include <stdio.h>
#include <stdlib.h>
#include "playgame.h"

void playGame(Queue *q)
{
  ElType val;
  printf("\nBerikut adalah daftar antrian game-mu\n");
  displayQueue(*q);
  if (isEmpty(*q))
  {
    printf("Antrian Kosong.\n");
  }
  else
  {
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
      printf("Game %s masih dalam maintenance, belum dapat dimainkan.\nSilahkan pilih game lain.", val);
    }
  }
}