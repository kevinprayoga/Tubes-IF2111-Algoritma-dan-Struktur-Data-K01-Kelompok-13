#ifndef STARTLOAD_H
#define STARTLOAD_H

#include "ADT\arraydin.h"
#include "ADT\mesinkar.h"
#include "ADT\mesinkata.h"
#include "ADT\mesinfile.h"
#include "function.h"

void start(ArrayDin *arr);
/* I.S. : Sembarang
   F.S. : Menampilkan pesan selamat datang dan menampilkan command yang tersedia
   Proses : Menampilkan pesan selamat datang dan menampilkan command yang tersedia */

void load(ArrayDin *arr, char *filename);
/* I.S. : Sembarang
   F.S. : Menampilkan pesan load berhasil dan memasukkan data dari file ke array
   Proses : Menampilkan pesan load berhasil dan memasukkan data dari file ke array */

#endif