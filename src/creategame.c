#include "creategame.h"

void customGame(ListMap *L, ArrayDin arr, ElType gameName)
{
    srand(time(0));
    int score = rand() % 100;
    printf("Skor akhir: %d\n", score);
    printf("Nama: ");
    keytype name = readQ();
    InsertToScoreboard(L, arr, gameName, name, score);
}

void createGame(ArrayDin *list_game, ListMap *L)
{
    printf("\nMasukkan nama game yang akan ditambahkan: ");
    STARTWORD();
    boolean found;
    found = false;
    int j = 0;
    char *cc;
    char *cc2;
    cc2 = wordToString(currentWord);

    if (!(IsEmpty(*list_game)))
    {
        while (j < Length(*list_game) && found == false)
        {
            cc = (*list_game).A[j];
            if ((strcompare(cc2, cc)))
            {
                found = true;
            }
            j++;
        }
    }
    if (found == true)
    {
        printf("Game sudah tersedia.\n");
    }
    else
    {
        InsertLast(list_game, cc2);
        CreateEmptyMap(L);
        printf("Game berhasil ditambahkan\n");
    }
}