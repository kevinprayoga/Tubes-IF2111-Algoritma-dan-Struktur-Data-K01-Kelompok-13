#include "skipgame.h"

//cek apakah next command itu berupa integer
boolean isInteger(char arg)
{
    boolean k;
	if ((arg>='0') && (arg<='9')){
        k = 1;
    }
    return k;
}

//prosedur skipgame
void SkipGame(Queue* Game, int command3)
{
    
    PLAYGAME(Game->buffer[command3-1]);

   /* if (command1 == "SKIPGAME")
    {
        ADVWORD();
        command2 = wordToString(currentWord);

        //membaca kata kedua dalam command
        command3 = wordToInt(currentWord);
        if (isInteger(command2))
        {
            valid = true;
        }
    }

    if (valid) 
    {
        if (command3 <= length(*Game))
        {
            PLAYGAME(*Game); // memulai game yang ke-a dihitung dari 0
        }
    }*/
}