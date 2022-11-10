#include "skipgame.h"
#include "playgame.h"

void SkipGame(Queue *Game, int command3)
{
    ElType var;
    displayQueue(*Game);
    if (command3 > 0 && command3 <= length(*Game))
    {
        for (int i = 0; i < command3; i++)
        {
            dequeue(Game, &var);
        }
        playGame(Game);
    }
    else if (command3 > length(*Game))
    {
        for (int i = 0; i < length(*Game); i++)
        {
            dequeue(Game, &var);
        }   
        printf("Tidak ada permainan lagi dalam daftar game-mu.\n");
    }
    playGame(Game);
}