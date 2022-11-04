#include "quit.h"


void Quit(Queue *Game){
    while (length(*Game) != 0){
        int val;
        dequeue(Game, &val);
    }

    printf("Anda kelur dari game BNMO.\n");
    printf("Bye bye...\n");
    exit(0);
}
