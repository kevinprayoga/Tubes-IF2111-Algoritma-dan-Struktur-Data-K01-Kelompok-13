#include "creategame.h"

void customGame(ListMap *L, ArrayDin arr, ElType gameName)
{
    srand(time(0));
    int nilai = rand() % 100;
    printf("Skor: %d\n", nilai);
    InsertToScoreboard(L, arr, gameName, nilai);
}

void createGame(ArrayDin *list_game, ListMap *L)
{
    printf("\nMasukkan nama game yang akan ditambahkan: ");
    STARTWORD();
    int j = 0;
    boolean found = false;
    char *cc;
    char *cc2;
    cc2 = wordToString(currentWord);
    if (!(IsEmpty(*list_game)))
    {
        while (j < Length(*list_game) && !found)
        {
            cc = (*list_game).A[j];
            if ((strcompare(cc2, cc)))
            {
                found = true;
            }
            j++;
        }
    }
    if (found)
    {
        printf("Game sudah tersedia.\n");
    }
    else
    {
        if (strcompare(cc2, "CREATE GAME"))
        {
            commandLain();
        }
        else
        {
            InsertLast(list_game, cc2);
            CreateEmptyMap(L);
            printf("Game berhasil ditambahkan.\n");
        }
    }
}  