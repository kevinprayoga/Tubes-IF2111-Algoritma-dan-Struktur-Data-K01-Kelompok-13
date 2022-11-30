#include <stdio.h>
#include <stdlib.h>
#include "playgame.h"

void playGame(Queue *q, Stack *s, ListMap *l, ArrayDin arr)
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
    if (strcompare(val, "RNG") || strcompare(val, "Diner DASH") || strcompare(val, "HANGMAN") || strcompare(val, "TOWER OF HANOI") || strcompare(val, "SNAKE ON METEOR") || strcompare(val, "Minesweeper"))
    {
      printf("Loading %s ...\n", val);
      printf("\nPress ENTER key to play %s...", val);
      fgetchar();
      system("cls");
      if (strcompare(val, "RNG"))
      {
        InsertToScoreboard(l, arr, val, RNG());
        // mulai game RNG
      }
      else if (strcompare(val, "Diner DASH"))
      {
        InsertToScoreboard(l, arr, val, dinerdash());
        // mulai game diner dash
      }
      else if (strcompare(val, "HANGMAN"))
      {
        // mulai game HANGMAN
      }
      else if (strcompare(val, "TOWER OF HANOI"))
      {
        // mulai game TOWER OF HANOI
      }
      else if (strcompare(val, "SNAKE ON METEOR"))
      {
        // mulai game SNAKE ON METEOR
      }
      else if (strcompare(val, "Minesweeper"))
      {
        playmine();
        // mulai game minesweeper
      }
    }
    else
    {
      printf("\n\nLoading %s ...\n", val);
      printf("\nPress ENTER key to play %s...", val);
      fgetchar();
      system("cls");
      customGame(l, arr, val);
    }
  }
}