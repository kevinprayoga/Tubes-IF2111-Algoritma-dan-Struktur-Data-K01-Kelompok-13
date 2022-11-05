#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include ".\ADT\mesinkata.h"
#include ".\ADT\mesinkarakter.h"
#include ".\ADT\queue.h"
#include "console.h"
#include "queuegame.h"

#ifndef SKIP_GAME_
#define SKIP_GAME_

boolean isInteger(int arg);

void SkipGame(Queue* Game, ArrayDin arrReady);

#endif