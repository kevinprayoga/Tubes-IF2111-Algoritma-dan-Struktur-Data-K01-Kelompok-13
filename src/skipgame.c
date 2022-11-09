#include "skipgame.h"

void SkipGame(Queue* Game, int command3)
{
    char* var;
    for(int i=0; i<command3; i++){
        dequeue(Game, var);
    }
}