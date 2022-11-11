#include <stdio.h>
#include <stdlib.h>
#include "deletegame.h"

void deleteGame(ArrayDin *arr, Queue q)
{
  int num;
  ElType val;
  ListGame(arr);
  printf("Masukkan nomor game yang akan dihapus: ");
  STARTWORD();
  num = wordToInt(currentWord);
  val = (*arr).A[num - 1];
  if ((num - 1 > 5) && (num - 1 < Length(*arr)) && (!(isMemberQ(q, val))))
  {
    DeleteAt(arr, num - 1);
    printf("\nGame berhasil dihapus");
  }
  else
  {
    printf("\nGame gagal dihapus");
  }
}