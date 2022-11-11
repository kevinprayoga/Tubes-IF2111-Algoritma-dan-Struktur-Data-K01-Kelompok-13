#include "skipgame.h"
#include "playgame.h"

void SkipGame(Queue *Game, int command3)
{
    printf("Game berhasil di-SKIP\n");
    ElType var;
    int len = length(*Game);
    if (command3 > 0 && command3 <= len)
    {
        for (int i = 0; i < command3; i++)
        {
            dequeue(Game, &var);
        }
        playGame(Game);
    }
    else if (command3 > len)
    {
        for (int i = 0; i < len; i++)
        {
            dequeue(Game, &var);
        }   
        printf("Tidak ada permainan lagi dalam daftar game-mu.\n");
    }
}