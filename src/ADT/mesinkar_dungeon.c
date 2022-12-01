#include <stdio.h>
#include "mesinkar_dungeon.h"

/* State Mesin */
char curr;
boolean terminate;

static FILE *p;
static int rv;

void startArt(char* name){
    p = fopen(name, "r");
    advArt();
}

void advArt(){
  rv = fscanf(p, "%c", &curr);
}

void printArt(char* name){
	startArt(name);
	while(curr != end){
		printf("%c", curr);
		advArt();
	}
	fclose(name, "r");
}