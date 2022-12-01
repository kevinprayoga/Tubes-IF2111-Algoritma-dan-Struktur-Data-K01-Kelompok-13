#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "alstrokedungeon.h"
#include "function.h"

Tree create_map(int level, int difficulty){
	/*
	 * Menginisialisasi map dungeon
	 * input jumlah level (kedalaman dungeon), dan kesulitan dungeon
	 * output berupa map dungeon yang siap dimainkan
	 */
	int i, d;
	srand(time(0));

    Tree p;
    Address l, m, r;
	ListOfNode arrLevel[level];
	if(rand() % 100 < difficulty * 10){
    	l = newNode(0);
	}
    if(rand() % 100 < difficulty * 10){
    	m = newNode(0);
	}
	if(rand() % 100 < difficulty * 10){
       	r = newNode(0);
	}
    p = createTree(0, l, m, r, level, difficulty);

	for(int i = 1; i <= level; i++){
		makeListLevel(&(arrLevel[i-1]), &p, i);
	}
	addr loc;
	for(int i = 0; i < level; i++){
		loc = arrLevel[i];
		while(loc != Nil){
			Info(Elmt(loc)) = rand() % difficulty;
			loc = Next(loc);
		}
	}
	return p;
}

void startArt(char* filename){
    pita = fopen(filename, "r");
    ADV();
}

void printArt(char* filename){
	startArt(filename);
	while(currentChar != ':'){
		printf("%c", currentChar);
		ADV();
	}
	fclose(filename, "r");
}

void print_dungeon(Tree *p){
	/*
	 * Menampilkan peta dungeon ke layar
	 * input berupa tree tidak kosong
	 */
	switch(*p)
		case isOneElmt(*p):
			printArt("portal.txt");
		case isNoneLeft(*p) && isNoneMid(*p):
			printArt("R.txt");
		case isNoneLeft(*p) && isNoneRight(*p):
			printArt("M.txt");
		case isNoneMid(*p) && isNoneRight(*p):
			printArt("L.txt");
		case isNoneLeft(*p):
			printArt("MR.txt");
		case isNoneMid(*p):
			printArt("LR.txt");
		case isNoneRight(*p):
			printArt("LM.txt");
		case isTerner(*p):
			printArt("LMR.txt");
}

int playdungeon(){
	int seed_lvl, seed_diff;
	int input_comm;
	printArt("title.txt");

}