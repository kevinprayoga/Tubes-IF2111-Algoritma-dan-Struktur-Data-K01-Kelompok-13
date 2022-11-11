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
      //mulai game diner dash
    }
    else if (strcompare(val, "Minesweeper"))
    {
      playmine();
      //mulai game minesweeper
    }
    else if (strcompare(val, "DINOSAUR IN EARTH"))
    {
      printf("\nGame %s masih dalam maintenance, belum dapat dimainkan.\nSilahkan pilih game lain.\n", val);
    }
    else if (strcompare(val, "DRISEWOMAN"))
    {
      printf("\nGame %s masih dalam maintenance, belum dapat dimainkan.\nSilahkan pilih game lain.\n", val);
    }
    else if (strcompare(val, "EIFFEL TOWER"))
    {
      printf("\nGame %s masih dalam maintenance, belum dapat dimainkan.\nSilahkan pilih game lain.\n", val);
    } else {
      customGame();
    }
  }
}