#include "skipgame.h"
#include "playgame.h"

void SkipGame(Queue* Game, int command3)
{

    ElType var;
    for(int i=0; i<command3; i++){
        dequeue(Game, &var);
    }
    playGame(Game);
}