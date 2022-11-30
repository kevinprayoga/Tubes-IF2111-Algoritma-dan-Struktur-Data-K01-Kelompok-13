#include <stdio.h>
#include "scoreboard.h"

void InsertToScoreboard(ListMap *L, ArrayDin arr, ElType gameName, valuetype score)
{
  int num = GetNum(arr, gameName);
  printf("Nama: ");
  keytype name = readQ();
  while (IsMemberMap(*L, name, num))
  {
    printf("\nNama sudah ada di scoreboard, silahkan ketik ulang!\n");
    printf("\nNama: ");
    name = readQ();
  }
  printf("Nama anda berhasil dimasukkan ke scoreboard!\n");
  InsertMap(L, name, score, num);
}

void scoreboard(ListMap L, ArrayDin arr)
{
  for (int i = 0; i < L.total; i++)
  {
    printf("**** SCOREBOARD %s ****\n", arr.A[i]);
    printf("| NAMA\t\t|SKOR\t\t|\n");
    printf("|-----------------------|\n");
    if (IsEmptyMap(L, i + 1))
    {
      printf("---- SCOREBOARD KOSONG ----\n\n");
    }
    else
    {
      for (int j = 0; j < L.list[i].Count; j++)
      {
        printf("| %s\t\t|%d\t\t|\n", L.list[i].Elements[j].Key, L.list[i].Elements[j].Value);
      }
      printf("\n");
    }
  }
}