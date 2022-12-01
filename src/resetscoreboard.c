#include <stdio.h>
#include "resetscoreboard.h"
#include <stdlib.h>

void resetscoreboard(ListMap *L, ArrayDin arr)
{
  printf("\nDAFTAR SCOREBOARD:\n");
  printf("0. ALL\n");
  for (int i = 0; i < Length(arr); i++)
  {
    printf("%d. %s\n", i+1, arr.A[i]);
  }

  printf("\nSCOREBOARD YANG INGIN DIHAPUS: ");
  char *strnum = readQ();
  if (strcompare(strnum, "RESET SCOREBOARD"))
  {
    commandLain();
  }
  else
  {
    int num = strToInt(strnum);
    if (num == 0)
    {
      printf("\nAPAKAH KAMU YAKIN INGIN MELAKUKAN RESET SCOREBOARD ALL (YA/TIDAK)? ");
    }
    else
    {
      printf("\nAPAKAH KAMU YAKIN INGIN MELAKUKAN RESET SCOREBOARD %s (YA/TIDAK)? ", arr.A[num - 1]);
    }

    char *kalimat = readQ();

    if (strcompare(kalimat, "YA") || strcompare(kalimat, "ya"))
    {
      if (num == 0)
      {
        int len = L->total;
        for (int i = 0; i < len; i++)
        {
          L->list[i].Count = Nilz;
        }
        printf("\nScoreboard berhasil di-reset.\n");
      }
      else if (num > 0)
      {
        L->list[num - 1].Count = Nilz;
        printf("\nScoreboard berhasil di-reset.\n");
      }
      else
      {
        printf("\nINPUT TIDAK VALID!\n");
      }
    }
    else if (strcompare(kalimat, "TIDAK") || strcompare(kalimat, "tidak"))
    {
      printf("\nRESET SCOREBOARD DIBATALKAN!\n");
    }
    else
    {
      commandLain(); 
    }
  }
}