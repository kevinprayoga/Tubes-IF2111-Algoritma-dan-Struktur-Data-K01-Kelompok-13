#include "skipgame.h"

//cek apakah next command itu berupa integer
boolean isInteger(int arg)
{
    boolean check = false;
    if (arg >= 48 && arg <=57)
    {
        check = true;
    }
    return check;
}

//prosedur skipgame
void SkipGame(Queue* Game, ArrayDin arrReady)
{
    char* command1, command2;
    int command3;
    boolean valid = false;
    command1 = *readQ(); //membaca kata pertama dalam command

    if (command1 == "SKIPGAME")
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
            PLAYGAME(*Game, arrReady.A[command3-1]); // memulai game yang ke-a dihitung dari 0
        }
    }
}