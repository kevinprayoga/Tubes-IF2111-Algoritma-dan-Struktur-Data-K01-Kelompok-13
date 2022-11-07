#include <stdio.h>
#include "listgame.h"
#include "console.h"

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
{
    // KAMUS
    int i = 0;
    char command, command2;

    command = *readQ();
    if (command == "LIST")
    {
        ADVWORD();
        command2 = wordToString(currentWord);
        if (command2 == "GAME")
        {
            printf("Berikut adalah daftar game yang tersedia\n");
            for (i = 0; i < Length(*list_game); i++)
            {
                printf(">>%d %s", i+1, (*list_game).A[i]);
            }
        }
    }
}