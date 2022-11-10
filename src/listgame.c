#include <stdio.h>
#include "listgame.h"

// typedef int IdxType;
// typedef int ElType;
// typedef struct {
//     ElType *A;
//     int Capacity;
//     int Neff;
// } ArrayDin;

void ListGame(ArrayDin *list_game)
/*
Menampilkan daftar game yang disediakan oleh sistem
Prekondisi: list_game tidak mungkin kosong karena 5 game pada konfigurasi
            pertama tidak dapat dihapus.
*/
{ int i;
    // KAMUS
    printf("\nBerikut adalah daftar game yang tersedia : \n");
    for (i = 0; i < Length(*list_game); i++)
    {
        printf("\t%d. %s\n", i+1, (*list_game).A[i]);
    }
}