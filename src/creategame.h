#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include ".\ADT\mesinkatav2.h"
#include ".\ADT\mesinkarakterv2.h"
#include ".\ADT\arraydin.h"

#ifndef CREATE_GAME_
#define CREATE_GAME_

int ranNum();

void createGame(ArrayDin* List);

char *WordToStr(Word kata);

int stringLength(char *str);

boolean strcompare(char *str1, char *str2);

#endif