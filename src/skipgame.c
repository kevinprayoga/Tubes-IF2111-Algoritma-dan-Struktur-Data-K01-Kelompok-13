#include "skipgame.h"

boolean isInteger(char arg)
{
    boolean k;
	if ((arg>='0') && (arg<='9')){
        k = 1;
    }
    return k;
}

Queue skipQueue(Queue* Game, int a){
    Queue New;
    CreateQueue(&New);
    enqueue(&New, Game->buffer[a-1]);
    for(int i = 0; i <= IDX_TAIL(*Game)-1; i++){
        if (Game->buffer[i] != Game->buffer[a-1]){
            enqueue(&Game, Game->buffer[i]);
        }
    }
    return New;
}

void SkipGame(Queue* Game, int command3)
{
    skipQueue(Game, command3);
    PLAYGAME(Game);

}