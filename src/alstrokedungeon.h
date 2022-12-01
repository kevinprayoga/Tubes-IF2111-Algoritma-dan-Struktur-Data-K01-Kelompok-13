#ifndef __ALSTROKEDUNGEON__
#define __ALSTROKEDUNGEON__

#include "boolean.h"
#include "ADT/mesinkar_dungeon.h"
#include "ADT/mesinkar.h"
#include "ADT/dungeon_tree.h"

#define undef -1

Tree create_map(int level, int difficulty);

void startArt(char* filename);

void printArt(char* filename);

void print_dungeon(Tree *p);

int playdungeon();

#endif
