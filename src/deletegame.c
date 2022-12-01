#include <stdio.h>
#include <stdlib.h>
#include "deletegame.h"

void deleteGame(ArrayDin *arr, Stack *s, ListMap *l, Queue q)
{
  int num;
  ElType val;
  ListGame(arr);
  printf("\nMasukkan nomor game yang akan dihapus: ");
  STARTWORD();
  if (strcompare(wordToString(currentWord), "DELETE GAME"))
  {
    commandLain();
  }
  else
  {
    num = wordToInt(currentWord);
    val = arr->A[num - 1];
    if ((num - 1 > 5) && (num - 1 < Length(*arr)) && (!(isMemberQ(q, val))))
    {
      deleteHistory(s, *arr, num - 1);
      DeleteMap(l, num);
      DeleteAt(arr, num - 1);
      printf("\nGame berhasil dihapus.\n");
    }
    else
    {
      printf("\nGame gagal dihapus.\n");
    }
  }
}