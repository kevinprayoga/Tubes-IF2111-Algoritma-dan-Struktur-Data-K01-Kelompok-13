#include "./ADT/queue_dinerdash.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void show(QueueFood q1, QueueCook q2, int saldo);

void orderFood(QueueFood* q, int idx);

boolean isWordSame(Word command1, Word command2);

void dinerdash();