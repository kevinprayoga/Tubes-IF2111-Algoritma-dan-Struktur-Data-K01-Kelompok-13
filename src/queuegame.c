#include <stdio.h>
#include "queuegame.h"

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
            printf(">>%d. %s",i+1, Game->buffer[i]);
        }
    }

    //menampilkan game yang tersedia apabila user ingin menambahkan game baru ke dalam antrian
    ListGame(list_game);
    scanf("%d", &a);
    printf("Nomor Game yang mau ditambahkan ke antrian: %d", a);

    //proses menambahkan game ke dalam antrian dari list_game
    if (a <= Length(list_game))
    {
        enqueue(Game, list_game.A[a-1]);
        printf("Game berhasil ditambahkan kedalam daftar antrian.");
    }
    else
    {
        printf("Nomor permainan tidak valid, silahkan masukkan nomor game pada list.");
    }
}