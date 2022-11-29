#ifndef HISTORY_H
#define HISTORY_H

#include "ADT/stack.h"
#include "ADT/arraydin.h"

void history (Stack *s, int command);

void deleteHistory(Stack *s, ArrayDin arr, IdxType idx);

#endif