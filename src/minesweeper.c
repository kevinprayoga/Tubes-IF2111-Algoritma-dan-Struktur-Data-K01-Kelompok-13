#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "minesweeper.h"
#include "ADT/mesinkar.h"
#include "function.h"

minefield *create_field(int row, int col, int seed)
{
	/*
	 * Menginisialisasi ladang ranjau/minefield
	 * input jumlah baris, kolom, dan seed
	 * output berupa minefield yang siap dimainkan
	 */
	int i, j;
	srand(time(0));

	minefield *field = (minefield *)malloc(sizeof(minefield));
	field->row = row;
	field->col = col;
	field->cells = (cell *)malloc(row * col * sizeof(cell));

	// memasukkan value awal minefield
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			int idx = get_index(field, i, j);
			boolean is_mine = false;
			if ((rand() % 100) < seed * 10)
			{
				is_mine = true;
			}
			field->cells[idx].x = i;
			field->cells[idx].y = j;
			field->cells[idx].neighbour = 0;
			field->cells[idx].is_mine = is_mine;
			field->cells[idx].is_open = false;
			field->cells[idx].is_flag = false;
		}
	}

	// memasukkan jumlah mine disekitar
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			int idx = get_index(field, i, j);
			int neighbour = neighbour_mines(field, i, j);
			field->cells[idx].neighbour = neighbour;
		}
	}

	return field;
}

void print_field(minefield *field)
{
	/*
	 * Menampilkan minefield ke layar
	 * input berupa minefield
	 */
	int i, j;
	// bagian atas board
	for (i = 0; i < field->col; i++)
	{
		if (i == 0)
		{
			printf("  y \t  %d ", i);
		}
		else if (i < 10)
		{
			printf(" %d ", i);
		}
		else
		{
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

void print_cell(cell cell)
{
	/*
	 * Menampilkan isi dari sebuah cell
	 * input berupa cell yang akan diprint
	 */
	// Mengecek apakah cell tersebut diberi flag
	if (cell.is_flag)
	{
		printf(" F " RESET);
		return;
	}
	if (cell.is_open)
	{
		// apabila isi cell adalah mine
		if (cell.is_mine)
		{
			printf(" X " RESET);
			return;
		}
		// apabila cell tidak memiliki mine disekitar
		if (cell.neighbour == 0)
		{
			printf(" - " RESET);
			return;
		}

		// apabila cell memiliki mine disekitar
		printf(" %d " RESET, cell.neighbour);

		return;
	}
	// apabila cell belum dibuka
	printf(" ? " RESET);
}

boolean interact(minefield *field, int x, int y, char command)
{
	/*
	 * Berinteraksi dengan sebuah cell sesuai command yang diberikan
	 * input berupa minefield, posisi x dan y cell, dan command {o = open cell, f = flag cell}
	 * mengembalikan boolean apakah cell tersebut diberi flag atau dibuka
	 */
	if (command == 'o' || command == 'O')
	{
		return open_cell(field, x, y);
	}
	else if (command == 'f' || command == 'F')
	{
		flag_cell(field, x, y);
		return false;
	}
}

void open_blanks(minefield *field, int x, int y)
{
	/*
	 * Membuka semua cell kosong dari koordinat (x, y)
	 * Apabila sebuah cell kosong, cell tersebut akan terbuka juga
	 * input berupa minefield serta posisi x dan y cell kosong
	 */
	int i, j;
	int idx = get_index(field, x, y);
	// rekursif
	for (i = x - 1; i <= x + 1; i++)
	{
		for (j = y - 1; j <= y + 1; j++)
		{
			int idx_neighbour = get_index(field, i, j);
			if (idx_neighbour != undef && idx_neighbour != idx)
			{
				if (field->cells[idx_neighbour].is_open == false && field->cells[idx_neighbour].is_flag == false)
				{
					open_cell(field, i, j);
				}
			}
		}
	}
}

boolean open_cell(minefield *field, int x, int y)
{
	/*
	 * Membuka cell pada koordinat (x, y)
	 * Jika cell tidak memiliki mine di sekitar, ia akan membuka cell disekitarnya juga
	 * input berupa minefield serta posisi x dan y cell
	 * mengembalikan boolean apakah ia berupa mine atau tidak
	 */
	int idx = get_index(field, x, y);
	// apabila cell telah diberi flag
	if (field->cells[idx].is_flag)
	{
		return false;
	}

	// apabila cell telah dibuka, ia akan membuka cell sekitarnya
	if (field->cells[idx].is_open)
	{
		return open_neighbours(field, x, y);
	}

	field->cells[idx].is_open = true;
	// apabila cell tidak memiliki mine di sekitar, ia akan membuka cell disekitarnya juga
	if (field->cells[idx].neighbour == 0)
	{
		open_blanks(field, x, y);
	}
	return field->cells[idx].is_mine;
}

void flag_cell(minefield *field, int x, int y)
{
	/*
	 * Memberi atau mencabut flag pada cell koordinat (x, y)
	 * Jika cell telah dibuka, pemain tidak bisa memberi flag
	 * input berupa minefield serta posisi x dan y cell
	 */
	int idx = get_index(field, x, y);

	if (field->cells[idx].is_open)
	{
		return;
	}

	if (field->cells[idx].is_flag)
	{
		field->cells[idx].is_flag = false;
	}
	else
	{
		field->cells[idx].is_flag = true;
	}
}

boolean open_neighbours(minefield *field, int x, int y)
{
	/*
	 * Membuka semua cell disekitar sebuah cell tertentu
	 * Apabila cell diberi flag, cell tersebut tidak dibuka
	 * input berupa minefield serta posisi x dan y cell awal
	 * mengembalikan true apabila sebuah cell berisi mine
	 */
	int i, j;
	int idx = get_index(field, x, y);
	// rekursif
	for (i = x - 1; i <= x + 1; i++)
	{
		for (j = y - 1; j <= y + 1; j++)
		{
			int idx_neighbour = get_index(field, i, j);
			if (idx_neighbour != undef && idx_neighbour != idx)
			{
				if (field->cells[idx_neighbour].is_open == false && field->cells[idx_neighbour].is_flag == false)
				{
					if (field->cells[idx_neighbour].is_mine)
					{
						return true;
					}

					field->cells[idx_neighbour].is_open = true;
					// apabile ditemukan cell kosong
					if (field->cells[idx_neighbour].neighbour == 0)
					{
						open_blanks(field, i, j);
					}
				}
			}
		}
	}
	return false;
}

void open_all(minefield *field)
{
	/*
	 * Membuka semua cell pada minefield
	 * input berupa minefield
	 */
	int i, j;
	for (i = 0; i < field->row; i++)
	{
		for (j = 0; j < field->col; j++)
		{
			int idx = get_index(field, i, j);
			field->cells[idx].is_flag = false;
			field->cells[idx].is_open = true;
		}
	}
}

void open_all_mines(minefield *field)
{
	/*
	 * Membuka semua cell yang berisi mine
	 * input berupa minefield
	 */
	int i, j;
	for (i = 0; i < field->row; i++)
	{
		for (j = 0; j < field->col; j++)
		{
			int idx = get_index(field, i, j);
			if (field->cells[idx].is_mine)
			{
				field->cells[idx].is_flag = false;
				field->cells[idx].is_open = true;
			}
		}
	}
}

boolean verdict(minefield *field)
{
	/*
	 * Memeriksa apakah pemain telah memenangkan permainan
	 * input berupa minefield
	 * mengembalikan true jika semua cell yang tidak berisi mine telah dibuka
	 */
	int i, j;
	for (i = 0; i < field->row; i++)
	{
		for (j = 0; j < field->col; j++)
		{
			int idx = get_index(field, i, j);
			if (field->cells[idx].is_mine == false && field->cells[idx].is_open == false)
			{
				return false;
			}
		}
	}
	return true;
}

int get_index(minefield *field, int x, int y)
{
	/*
	 * Mengembalikan index cell pada papan/minefield
	 * Mengembalikan undef apabila diluar batas
	 * input berupa minefield serta posisi x dan y cell
	 * output berupa index cell tersebut
	 */
	if (x < 0 || x >= field->row || y < 0 || y >= field->col)
	{
		return undef;
	}
	return (x * field->col + y);
}

/*
 * Mengembalikan jumlah mine disekitar cell
 * Mengembalikan undef apabila cell tersebut adalah mine
 * input berupa minefield serta posisi x dan y cell
 * output berupa jumlah mine disekitar cell
 */
int neighbour_mines(minefield *field, int x, int y)
{
	int i, j, mines = 0;
	int idx = get_index(field, x, y);

	if (field->cells[idx].is_mine)
	{
		return undef;
	}

	for (i = x - 1; i <= x + 1; i++)
	{
		for (j = y - 1; j <= y + 1; j++)
		{
			int idx_neighbour = get_index(field, i, j);
			if (idx_neighbour != undef && idx_neighbour != idx)
			{
				if (field->cells[idx_neighbour].is_mine)
				{
					mines++;
				}
			}
		}
	}
	return mines;
}

int score(minefield *field)
{
	int i, j, count = 0;

	for (i = 0; i < field->row; i++)
	{
		for (j = 0; j < field->col; j++)
		{
			int idx = get_index(field, i, j);
			if (field->cells[idx].is_mine == true && field->cells[idx].is_flag == true)
			{
				count++;
			}
		}
	}

	return 10 * count;
}

int playmine()
{
	int init_row, init_col, init_seed;
	int input_row, input_col;
	char command;
	boolean game_over;
	boolean eop;
	boolean retry = true;
	boolean error = true;
	boolean cell_err = false;
	minefield *field;

	system("cls");
	printf("=== Minesweeper in BNMO ===\n\n");
	while (retry)
	{
		init_row = undef;
		init_col = undef;
		init_seed = undef;
		game_over = false;
		eop = false;
		while (init_row == undef || init_col == undef || init_seed == undef)
		{
			printf("Jumlah row yang diinginkan: ");
			STARTWORD();
			if (currentWord.TabWord[0] >= 2 && isNum(wordToString(currentWord)))
			{
				init_row = wordToInt(currentWord);
			}
			else
			{
				init_row = undef;
				error = true;
			}
			printf("Jumlah col yang diinginkan: ");
			STARTWORD();
			if (currentWord.TabWord[0] >= 2 && isNum(wordToString(currentWord)))
			{
				init_col = wordToInt(currentWord);
			}
			else
			{
				init_col = undef;
				error = true;
			}
			printf("Seed kesulitan yang diinginkan (1-2 mudah, 3-4 sedang, >=5 sulit): ");
			STARTWORD();
			if (currentWord.TabWord[0] >= 1 && isNum(wordToString(currentWord)))
			{
				init_seed = wordToInt(currentWord);
			}
			else
			{
				init_seed = undef;
				error = true;
			}
			if (error)
			{
				printf("Input Anda salah, coba lagi.\n");
				error = false;
			}
		}
		field = create_field(init_row, init_col, init_seed);
		system("cls");

		while (!eop && !game_over)
		{
			print_field(field);

			printf("\nPilih sebuah cell (format: x,y)\n");
			STARTWORD();
			if (currentWord.TabWord[0] && wordToInt(currentWord) < init_row && isNum(wordToString(currentWord)))
			{
				input_row = wordToInt(currentWord);
			}
			else
			{
				cell_err = true;
			}
			STARTWORD();
			if (currentWord.TabWord[0] && wordToInt(currentWord) < init_col && isNum(wordToString(currentWord)))
			{
				input_col = wordToInt(currentWord);
			}
			else
			{
				cell_err = true;
			}
			printf("Perintah ( o untuk membuka, f untuk menandai )\n");
			STARTWORD();
			if (currentWord.TabWord[0] == 'o' || currentWord.TabWord[0] == 'f' || currentWord.TabWord[0] == 'O' || currentWord.TabWord[0] == 'F')
			{
				command = currentWord.TabWord[0];
			}
			else
			{
				error = true;
			}
			if (error)
			{
				printf("Input Anda salah, coba lagi.\n");
				error = false;
			}
			else if (cell_err)
			{
				printf("Cell tidak ditemukan.\n");
				cell_err = false;
			}
			else
			{
				game_over = interact(field, input_row, input_col, command);
				eop = verdict(field);
			}
			system("cls");
		}

		if (eop)
		{
			int skor = score(field);
			open_all(field);
			print_field(field);
			printf("Anda menang!\n");
			printf("Skor Anda: %d\n", skor);
		}
		else
		{
			int skor = score(field);
			open_all_mines(field);
			print_field(field);
			printf("Anda kalah!\n");
			printf("Skor Anda: %d\n", skor);
		}

		printf("Bermain lagi? (y / n): ");
		STARTWORD();
		retry = strcompare(wordToString(currentWord), "y") || strcompare(wordToString(currentWord), "Y");
	}

	system("cls");
	printf("Selamat tinggal!\n");
	free(field);

	return 0;
}