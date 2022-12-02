#include "mesinkar_dungeon.h"
#include <stdio.h>

int main(){
    printf("\nMembuka file dan membaca karakter pertama : \n");
    startArt("test.txt");
    printf("\nMenampilkan karakter di jendela dari masukan mesin karakter : %c\n", curr);
    advArt();
    printf("\nApabila di advArt(), karakter di jendela menjadi : %c\n", curr);
    printf("\nMemasukkan nama file yang ingin ditampilkan : \n");
    printArt("test.txt");

    return 0;
}