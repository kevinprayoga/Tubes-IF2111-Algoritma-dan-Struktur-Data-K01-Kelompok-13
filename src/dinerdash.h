#include "./ADT/queue_dinerdash.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "coba.h"

#ifndef DINER_DASH_H
#define DINER_DASH_H

void show(QueueFood q1, QueueCook q2, int saldo);

void orderFood(QueueFood* q, int idx);

boolean isWordSame(Word command1, Word command2);

boolean isFoodFormat(Word food);

int foodtonum(Word food);

int searchIndexIdFood(QueueFood q, int id);

void checkCook(QueueCook* q);

int searchIndexIdCook(QueueCook q, int id);

Word getFirstWord(Word word);

Word getSecondWord(Word word);

Cook cookFood(QueueFood q, int i);

void dinerdash();

#endif