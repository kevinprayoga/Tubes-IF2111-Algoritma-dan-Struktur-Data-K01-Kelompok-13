#ifndef __ALSTROKEDUNGEON__
#define __ALSTROKEDUNGEON__

#include "../boolean.h"
#include "../ADT/mesinkar_dungeon.h"
#include "../ADT/mesinkar.h"
#include "../ADT/mesinkata.h"
#include "../ADT/dungeon_tree.h"

#define undef -1

Tree create_map(int level, int difficulty);

void print_dungeon(Tree *p);

void intro(boolean skip);

void outro();

int playdungeon();

#endif
