#include "skipgame.h"
#include "playgame.h"

void SkipGame(Queue *Game, Stack s, ListMap l, ArrayDin arr, int command3)
{
    ElType var;
    int len = length(*Game);
    if (command3 > 0 && command3 < len)
    {
        printf("Game berhasil di-SKIP\n");
        for (int i = 0; i < command3; i++)
        {
            dequeue(Game, &var);
        }
        playGame(Game, &s, &l, arr);
    }
    else if (command3 >= len)
    {
        if (!isEmpty(*Game))
        {
            printf("Game berhasil di-SKIP\n");
            for (int i = 0; i < len; i++)
            {
                dequeue(Game, &var);
            }
            printf("\nTidak ada permainan lagi dalam daftar game-mu.\n");
        }
        else
        {
            printf("Anda tidak memiliki antrian game.\n");
        }
    }
    else
    {
        printf("Masukkan angka yang valid!\n");
    }
}