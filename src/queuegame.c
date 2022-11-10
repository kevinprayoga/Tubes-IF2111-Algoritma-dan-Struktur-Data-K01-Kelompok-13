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
    printf("\nBerikut adalah daftar antrian Game-mu\n");
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
    int gameNum = 0;
    int j  = 0;
    boolean found = false;
    if (currentWord.TabWord[j] <= '9' && currentWord.TabWord[j] > '0'){
            gameNum += currentWord.TabWord[j] - '0';
            j++;
    }
    while(j < currentWord.Length && found == false){
        gameNum *= 10;
        if (currentWord.TabWord[j] <= '9' && currentWord.TabWord[j] > '0'){
            gameNum += currentWord.TabWord[j] - '0';
        } else {
            found = true;
        }
        j++;
    }
    if (!found){
        if (gameNum > Length(list_game)){
            printf("Game tidak tersedia.\n");
        } else{
            enqueue(Game, list_game.A[gameNum-1]);
            printf("Game berhasil dimasukkan ke dalam antrian.\n");
        }
    } else {
        printf("Command tidak dikenali, silakan masukan command yang valid.\n");
    }
/*    if (currentWord.TabWord[0]){
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
*/
}


