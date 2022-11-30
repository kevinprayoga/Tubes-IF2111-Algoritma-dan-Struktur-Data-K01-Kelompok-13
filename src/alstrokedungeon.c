#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "alstrokedungeon.h"
#include "ADT/mesinkar.h"
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
    for(i = 0; i <= level, i++){
        l = newNode(0);
        m = newNode(0);
        r = newNode(0);
        createTree(&p, 0, l, m, r);
	}
    assignInfo();
	return map;
}

void print_map(Tree *p){
	/*
	 * Menampilkan peta dungeon ke layar
	 * input berupa tree
	 */
	int i, j;
	// bagian atas board
	for (i = 0; i < field->col; i++){
		if (i == 0){
			printf("  y \t  %d ", i);
		}
		else if (i < 10){
			printf(" %d ", i);
		}
		else{
			printf("%d ", i);
		}
	}
	printf("\nx\n\n");

	for (i = 0; i < field->row; i++)
	{
		for (j = 0; j < field->col; j++)
		{
			// bagian kiri board
			if (j == 0)
			{
				printf("%d\t ", i);
			}
			int idx = get_index(field, i, j);
			print_cell(field->cells[idx]);
		}
		printf("\n");
	}
}