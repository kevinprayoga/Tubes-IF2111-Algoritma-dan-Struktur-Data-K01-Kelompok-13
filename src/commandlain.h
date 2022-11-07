#include <stdio.h>
#include "boolean.h"

#ifndef CMD_LAIN_
#define CMD_LAIN_

boolean isCommand(char command);
/*
Mengembalikan true apabila command dikenali
*/

void commandLain();
/*
Jika command tidak dikenali, maka program meminta input command baru
*/

boolean isWordSame(Word word1, Word word2);
/*
I.S. word1 dan word2 terakuisisi
F.S. mengembalikan nilai true jika word1 == word2, false jika sebaliknya
*/

#endif