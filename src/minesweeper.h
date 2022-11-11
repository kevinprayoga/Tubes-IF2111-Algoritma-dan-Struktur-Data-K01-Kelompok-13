#ifndef _MINESWEEPER_h
#define _MINESWEEPER_h

#include "boolean.h"

#define undef -1
#define RESET "\033[0m"

typedef struct cell{
	int x;
	int y;
	boolean is_mine;
	int neighbour;
	boolean is_open;
	boolean is_flag;
} cell;

typedef struct minefield{
	int row;
	int col;
	cell* cells;
} minefield;

minefield* create_field(int row, int col, int seed);
void print_field(minefield* field);
void print_cell(cell cell);
boolean interact(minefield* field, int x, int y, char command);
boolean open_cell(minefield* field, int x, int y);
void flag_cell(minefield* field, int x, int y);
void open_zeros(minefield* field, int x, int y);
boolean open_neighbours(minefield* field, int x, int y);
void open_all(minefield* field);
void open_all_mines(minefield* field);
boolean verdict(minefield* field);
int get_index(minefield* field, int x, int y);
int neighbour_mines(minefield* field, int x, int y);
int score(minefield* field);
int playmine();

#endif