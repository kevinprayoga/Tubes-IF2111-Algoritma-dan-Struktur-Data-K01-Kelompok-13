#include <stdio.h>
#include "resetscoreboard.h"

void resetscoreboard(ListMap *L, ArrayDin arr)
{
  printf("DAFTAR SCOREBOARD:\n");
  printf("0. ALL\n");
  ListGame(&arr);
  ArrayDin listtemp = MakeArrayDin();
  for (int i = 0; i <= Length(arr); i++)
  {
    if (i == 0)
    {
      InsertLast(&listtemp, "ALL");
    }
    else
    {
      InsertLast(&listtemp, arr.A[i - 1]);
    }
  }
  printf("SCOREBOARD YANG INGIN DIHAPUS: ");
  char *strnum = readQ();
  int num = strToInt(strnum);
  printf("APAKAH KAMU YAKIN INGIN MELAKUKAN RESET SCOREBOARD %s (YA/TIDAK)? ", listtemp.A[num]);
  char *str = readQ();
  if (strcompare(str, "YA") || strcompare(str, "ya"))
  {
    if (num == 0)
    {
      int len = L->total;
      for (int i = 0; i < len; i++)
      {
        DeleteMap(L, L->total);
        CreateEmptyMap(L);
      }
      printf("Scorboard berhasil di-reset.\n");
    }
    else if (num > 0)
    {
      L->list[num - 1].Count = Nilz;
      printf("Scorboard berhasil di-reset.\n");
    }
    else
    {
      printf("INPUT TIDAK VALID!\n");
    }
  }
  else if (strcompare(str, "TIDAK") || strcompare(str, "tidak"))
  {
    printf("RESET SCOREBOARD DIBATALKAN!\n");
  }
  else
  {
    printf("Command tidak dikenali, silakan masukan command yang valid.\n");
    resetscoreboard(L, arr);
  }
}