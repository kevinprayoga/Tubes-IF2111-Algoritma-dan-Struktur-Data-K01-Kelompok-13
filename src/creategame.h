#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include ".\ADT\mesinkata.h"
#include ".\ADT\mesinkarakter.h"
#include ".\ADT\arraydin.h"

#ifndef CREATE_GAME_
#define CREATE_GAME_

int ranNum();

void createGame(ArrayDin* List);

char *WordToStr(Word kata);

boolean strcompare(char *str1, char *str2);

#endif