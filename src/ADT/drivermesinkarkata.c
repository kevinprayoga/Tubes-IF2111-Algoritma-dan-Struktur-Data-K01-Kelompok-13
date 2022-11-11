#include "mesinkata.h"
#include <stdio.h>

int main(){
    printf("Memasukkan input dari keyboard untuk mesin kata : ");
    STARTWORD();
    printf("Menampilkan currentWord dari masukan mesin kata: ");
    for (int j = 0; j < currentWord.Length; j++){
        printf("%c", currentWord.TabWord[j]);
    }
    printf("\n");
    printf("\nMemasukkan input dari keyboard untuk mesin karakter: ");
    START();
    printf("Menampilkan currentChar dari masukan mesin karakter : %c\n", currentChar);
    ADV();
    printf("\nApabila di ADV(), currentChar menjadi : %c\n", currentChar);

    printf("\nMenampilkan setiap character setelah di ADV() dari masukan mesin karakter : ");
    for(int i = 0; i < currentWord.Length; i++){
        printf("\n%c", currentWord.TabWord[i]);
    }

    return 0;
}