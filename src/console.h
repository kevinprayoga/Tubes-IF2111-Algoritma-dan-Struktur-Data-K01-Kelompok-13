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

void load(ArrayDin *arr, char filename);
/* I.S. : Sembarang
   F.S. : Menampilkan pesan load berhasil dan memasukkan data dari file ke array
   Proses : Menampilkan pesan load berhasil dan memasukkan data dari file ke array */

void deleteGame(ArrayDin *arr, Queue q);
/* I.S. : Sembarang
   F.S. : Menghapus game dari array
   Proses : Menghapus game dari array */

void playGame(Queue *q, ArrayDin arrReady);
/* I.S. : Sembarang
   F.S. : Memainkan game yang sudah diambil dari queue
   Proses : Memainkan game yang sudah diambil dari queue */

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

boolean isMemberQ(Queue q, ElType val);
/* I.S. : Sembarang
   F.S. : Mengembalikan true jika val ada di dalam queue
   Proses : Mengembalikan true jika val ada di dalam queue */

#endif