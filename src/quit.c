#include "quit.h"


void Quit(){
    printf("Apakah anda ingin melakukan SAVE? (Y/N) ");
    STARTWORD();
    if (currentWord.TabWord[0] == 'Y' || currentWord.TabWord[0] == 'y'){
        printf("melakukan save\n");
        printf("Anda kelur dari game BNMO.\n");
        printf("Bye bye...\n");
        exit(0);
    } else if (currentWord.TabWord[0] == 'N' || currentWord.TabWord[0] == 'n'){
        printf("Anda kelur dari game BNMO.\n");
        printf("Bye bye...\n");
        exit(0);
    } else{
        printf("Command tidak dikenali, silakan masukan command yang valid.\n");
        Quit();
    }
}
