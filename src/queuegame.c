#include <stdio.h>
#include "queuegame.h"
#include "listgame.h"

/*
typedef char *ElType;
typedef struct
{
  ElType buffer[CAPACITY];
  int idxHead;
  int idxTail;
} Queue;
*/

void QueueGame(Queue *Game ,ArrayDin list_game){
    int a; // integer masukan game ke-

    //menampilkan daftar antrian game yang akan dimainkan
    printf("Berikut adalah daftar antrian game-mu\n");
    if (isEmpty(*Game)){
        printf("Antrian Kosong.");
    }
    else
    {
        for (int i = 0; i<= (Game->idxTail); i++)
        {
            printf("  %d. %s",i+1, Game->buffer[i]);
        }
    }

    //menampilkan game yang tersedia apabila user ingin menambahkan game baru ke dalam antrian
    ListGame(&list_game);
    printf("Masukkan nomor game yang ingin dimainkan: ");
    STARTWORD();
    if (currentWord.TabWord[0]){
        a = currentWord.TabWord[0] - '0';
        if (a > Length(list_game)){
            printf("Game tidak tersedia.\n");
        } else{
            enqueue(Game, list_game.A[a-1]);
        }
    } else{
        printf("Command tidak dikenali, silakan masukan command yang valid.\n");
    }
}

