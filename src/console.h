#ifndef CONSOLE__h
#define CONSOLE__h

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "ADT/arraydin.h"
#include "ADT/mesinkar.h"
#include "ADT/mesinkata.h"
#include "ADT/mesinfile.h"
#include "ADT/queue.h"
#include "ADT/queue_dinerdash.h"
#include "ADT/stack.h"
#include "ADT/stackTOH.h"
#include "ADT/listofmap.h"
#include "ADT/listlinier.h"
#include "ADT/point.h"
// #include "ADT/dungeon_tree.h"
// #include "ADT/mesinkar_dungeon.h"
#include "ADT/set.h"
#include "GAME/gameRNG.h"
#include "GAME/dinerdash.h"
#include "GAME/minesweeper.h"
#include "GAME/towerofhanoi.h"
#include "GAME/hangmanset.h"
#include "GAME/asciihangman.h"
#include "GAME/snake.h"
// #include "GAME/"
#include "boolean.h"

// WELCOMPAGE
void welcompage();

// START
void start(ArrayDin *arr);
/* I.S. : Sembarang
   F.S. : Menampilkan pesan selamat datang dan menampilkan command yang tersedia
   Proses : Menampilkan pesan selamat datang dan menampilkan command yang tersedia */

// LOAD
void load(ArrayDin *arr, Stack *s, ListMap *L, char *filename);
/* I.S. : Sembarang
   F.S. : Menampilkan pesan load berhasil dan memasukkan data dari file ke array
   Proses : Menampilkan pesan load berhasil dan memasukkan data dari file ke array */

// LIST GAME
void ListGame(ArrayDin *list_game);
/*
Menampilkan daftar game yang disediakan oleh sistem
Prekondisi: list_game tidak mungkin kosong karena 5 game pada konfigurasi
            pertama tidak dapat dihapus. */

// QUEUE GAME
void QueueGame(Queue *Game, ArrayDin list_game);

// CREATE GAME
void customGame(ListMap *L, ArrayDin arr, ElType gameName);

void createGame(ArrayDin *list_game, ListMap *L);

// DELETE GAME
void deleteGame(ArrayDin *arr, Stack *s, ListMap *l, Queue q);
/* I.S. : Sembarang
   F.S. : Menghapus game dari array
   Proses : Menghapus game dari array */

// SKIP GAME
void SkipGame(Queue *Game, Stack s, ListMap l, ArrayDin arr, int command3);
/*
I.S: Queue game yang sudah memiliki urutan sesuai.
F.S: Queue yang sudah diganti urutannya dan siap untuk dilakukan playgame. */

// PLAY GAME
void playGame(Queue *q, Stack *s, ListMap *l, ArrayDin arr);

// SCOREBOARD
void InsertToScoreboard(ListMap *L, ArrayDin arr, ElType gameName, valuetype score);

void scoreboard(ListMap L, ArrayDin arr);

// RESET SCOREBOARD
void resetscoreboard(ListMap *L, ArrayDin arr);

// HISTORY
void history(Stack *s, int command);

void deleteHistory(Stack *s, ArrayDin arr, IdxType idx);

// RESET HISTORY
void resetHistory(Stack *s);

// SAVE
void save(char *filename, ArrayDin listGame, Stack s, ListMap L);

// HELP
void help();
/* Menampilkan bantuan/deskripsi dari command yang ada. */

// QUIT
void Quit(ArrayDin list, Stack s, ListMap l);

// COMMAND LAIN
void commandLain();
/* Jika command tidak dikenali, maka program meminta input command baru */

// FUNCTION
char *readQ();
/* I.S. : Sembarang
   F.S. : Mengembalikan string yang sudah diinputkan
   Proses : Membaca string yang sudah diinputkan */

boolean strcompare(char *str1, char *str2);

int stringLength(char *str);

char *wordToString(Word word);
/* I.S. : Sembarang
   F.S. : Mengembalika string dari word
   Proses : Mengembalikan string dari word */

int wordToInt(Word word);
/* I.S. : Sembarang
   F.S. : Mengembalikan integer dari word
   Proses : Mengembalikan integer dari word */

char *firststring(char *command);

char *secondstring(char *command);

char *thirdstring(char *command);

int space_char(char *str);

char *strconcat(char *dest, char *src);

boolean isMemberQ(Queue q, char *val);

int strToInt(char *str);

boolean isNum(char *str);

#endif