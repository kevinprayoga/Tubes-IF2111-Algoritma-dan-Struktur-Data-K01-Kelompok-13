#include <stdio.h>
#include <stdlib.h>
#include "deletegame.h"

void deleteGame(ArrayDin *arr, Queue q)
{
  int num;
  ElType val;
  printf("Berikut adalah daftar game yang tersedia\n");
  for (int i = 0; i < arr->Neff; i++)
  {
    printf("%d. %s\n", i + 1, arr->A[i]);
  }
  scanf("Masukkan nomor game yang akan dihapus: %d\n", &num);
  val = arr->A[num - 1];
  if (num - 1 > 4 && num - 1 < Length(*arr) && (!isMemberQ(q, val)))
  {
    DeleteAt(arr, num - 1);
    printf("\nGame berhasil dihapus");
  }
  else
  {
    printf("\nGame gagal dihapus");
  }
}