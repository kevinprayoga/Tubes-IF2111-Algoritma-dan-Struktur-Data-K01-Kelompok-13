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
    printf("\nBerikut adalah daftar antrian game-mu\n");
    if (isEmpty(*Game)){
        printf("Antrian Kosong.\n");
    }
    else
    {
        int num= 1;
        for (int i = IDX_HEAD(*Game); i<= ((*Game).idxTail); i++)
        {
            printf("\t%d. %s\n",num, (*Game).buffer[i]);
            num++;
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
            printf("Game berhasil dimasukkan ke dalam antrian.\n");
        }
    } else{
        printf("Command tidak dikenali, silakan masukan command yang valid.\n");
    }
}

