#include "quit.h"
#include "save.h"

void Quit(ArrayDin list, Stack s, ListMap l)
{
    printf("Apakah anda ingin melakukan SAVE? (Y/N) ");
    STARTWORD();
    char *filename;
    if (currentWord.TabWord[0] == 'Y' || currentWord.TabWord[0] == 'y')
    {
        printf("Masukkan nama file: ");
        STARTWORD();
        filename = wordToString(currentWord);
        save(filename, list, s, l);
        printf("Anda keluar dari game BNMO.\n");
        printf("Bye bye...\n");
    }
    else if (currentWord.TabWord[0] == 'N' || currentWord.TabWord[0] == 'n')
    {
        printf("Anda keluar dari game BNMO.\n");
        printf("Bye bye...\n");
    }
    else
    {
        printf("Command tidak dikenali, silakan masukan command yang valid.\n");
        Quit(list, s, l);
    }
}
