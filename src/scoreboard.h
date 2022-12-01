#ifndef SCOREBOARD__H
#define SCOREBOARD__H

#include "ADT/listofmap.h"
#include "ADT/arraydin.h"
#include "function.h"
#include "commandlain.h"

void InsertToScoreboard(ListMap *L, ArrayDin arr, ElType gameName, valuetype score);

void scoreboard(ListMap L, ArrayDin arr);

#endif