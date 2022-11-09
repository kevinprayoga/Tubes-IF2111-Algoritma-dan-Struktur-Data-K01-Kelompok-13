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

// fungsi untuk mengecek apakah argumen merupakan masukan integer atau tidak
boolean isInteger(char arg);


//fungsi untuk mengubah urutan queue dengan buffer ke-a menjadi urutan pertama
Queue skipQueue(Queue* Game, int a);



void SkipGame(Queue* Game, int command3);
/*
I.S: Queue game yang sudah memiliki urutan sesuai.
F.S: Queue yang sudah diganti urutannya dan siap untuk dilakukan playgame.
*/

#endif