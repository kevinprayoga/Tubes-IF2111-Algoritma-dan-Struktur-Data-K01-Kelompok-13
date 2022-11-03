#ifndef __CONSOLE_H__
#define __CONSOLE_H__

#include "boolean.h"
#include "ADT\arraydin.h"
#include "ADT\mesinkata.h"
#include "ADT\queue.h"

void start(ArrayDin *arr);
/* I.S. : Sembarang
   F.S. : Menampilkan pesan selamat datang dan menampilkan command yang tersedia
   Proses : Menampilkan pesan selamat datang dan menampilkan command yang tersedia */

char *readQ();
/* I.S. : Sembarang
   F.S. : Mengembalikan string yang sudah diinputkan
   Proses : Membaca string yang sudah diinputkan */

char wordToString(Word word);
/* I.S. : Sembarang
   F.S. : Mengembalika string dari word
   Proses : Mengembalikan string dari word */

int wordToInt(Word word);
/* I.S. : Sembarang
   F.S. : Mengembalikan integer dari word
   Proses : Mengembalikan integer dari word */

void deleteGame(ArrayDin *arr, ArrayDin arrFirst);
/* I.S. : Sembarang
   F.S. : Menghapus game dari array
   Proses : Menghapus game dari array */

void playGame(Queue *q);

#endif