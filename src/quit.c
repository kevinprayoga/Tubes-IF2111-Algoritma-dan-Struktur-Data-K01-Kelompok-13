#include "quit.h"
#include "save.h"


void Quit(ArrayDin list){
    printf("Apakah anda ingin melakukan SAVE? (Y/N) ");
    STARTWORD();
    char* filename;
    if (currentWord.TabWord[0] == 'Y' || currentWord.TabWord[0] == 'y'){
        printf("Masukkan nama file: \n");
        STARTWORD();
        filename = wordToString(currentWord);
        save(filename, list);
        printf("Anda kelur dari game BNMO.\n");
        printf("Bye bye...\n");
        exit(0);
    } else if(currentWord.TabWord[0] == 'N' || currentWord.TabWord[0] == 'n'){
        printf("Anda keluar dari game BNMO.\n");
        printf("Bye bye...\n");
        exit(0);
    }else{
        printf("Command tidak dikenali, silakan masukan command yang valid.\n");
        Quit(list);
    }
}
