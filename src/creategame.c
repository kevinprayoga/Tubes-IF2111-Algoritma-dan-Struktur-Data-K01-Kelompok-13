#include "creategame.h"

int customGame(){
    srand(time(0));
    printf("Skor akhir Anda = %d\n", rand()%100);
}

void createGame(ArrayDin* list_game){
    printf("\nMasukkan nama game yang akan ditambahkan: ");
    STARTWORD();
    boolean found;
    found = false;
    int j = 0;
    char* cc;
    char* cc2;
    cc2 = wordToString(currentWord);
    printf("%s\n", cc2);

    if (!(IsEmpty(*list_game))){
        while (j < Length(*list_game) && found == false){
            cc = (*list_game).A[j];
            if ((strcompare(cc2, cc))){
                found = true;
            }
        j++;
        }
    }
    if (found == true){
        printf("Game sudah tersedia.\n");
    } else{
        InsertLast(list_game, cc2);
        printf("Game berhasil ditambahkan\n");
    }
}

