#include <stdio.h>
#include "scoreboard.h"

void InsertToScoreboard(ListMap *L, ArrayDin arr, ElType gameName, valuetype score)
{
  int num = GetNum(arr, gameName);
  printf("Nama: ");
  char *name = readQ();
  while (IsMemberMap(*L, name, num))
  {
    printf("\nNama sudah ada di scoreboard, silahkan ketik ulang!\n");
    printf("\nNama: ");
    name = readQ();
  }
  if (stringLength(name) > 13 || strcompare(name, "PLAY GAME"))
  {
    printf("\nNama terlalu panjang atau tidak valid, silahkan ketik ulang!\n");
    InsertToScoreboard(L, arr, gameName, score);
  }
  else if (stringLength(name) <= 13 && stringLength(name) > 0)
  {
    InsertMap(L, name, score, num);
    printf("\nNama anda berhasil dimasukkan ke scoreboard!\n");
  }
}

void scoreboard(ListMap L, ArrayDin arr)
{
  printf("\n");
  for (int i = 0; i < L.total; i++)
  {
    if (IsEmptyMap(L, i + 1))
    {
      printf("**** SCOREBOARD GAME %s ****\n", arr.A[i]);
      printf("| NAMA\t\t|SKOR\t\t|\n");
      printf("------- SCOREBOARD KOSONG -------\n\n");
    }
    else
    {
      printf("**** SCOREBOARD GAME %s ****\n", arr.A[i]);
      printf("| NAMA\t\t|SKOR\t\t|\n");
      printf("|-------------------------------|\n");
      for (int j = 0; j < L.list[i].Count; j++)
      {
        printf("| ");
        printf("%s", L.list[i].Elements[j].Key);
        if (stringLength(L.list[i].Elements[j].Key) <= 13)
        {
          printf("\t");
          if (stringLength(L.list[i].Elements[j].Key) <= 5)
          {
            printf("\t");
          }
        }
        printf("| %d\t\t|\n", L.list[i].Elements[j].Value);
      }
      printf("\n");
    }
  }
}