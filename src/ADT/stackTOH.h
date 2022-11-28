#ifndef stackTOH_H
#define stackTOH_H

#include "../boolean.h"

#define Nil -1
#define MaxEl 100
/* Nil adalah Tower dengan elemen kosong . */

typedef int infotype;
typedef int address;   /* indeks tabel */

/* Contoh deklarasi variabel bertype Tower dengan ciri TOP : */
/* Versi I : dengan menyimpan tabel dan alamat top secara eksplisit*/
typedef struct { 
  infotype T[MaxEl]; /* tabel penyimpan elemen */
  address TOP;  /* alamat TOP: elemen puncak */
} Tower;
/* Definisi Tower S kosong : S.TOP = Nil */
/* Elemen yang dipakai menyimpan nilai Tower T[0]..T[MaxEl-1] */
/* Jika S adalah Tower maka akses elemen : */
   /* S.T[(S.TOP)] untuk mengakses elemen TOP */
   /* S.TOP adalah alamat elemen TOP */

/* Definisi akses dengan Selektor : Set dan Get */
#define Top(S) (S).TOP
#define InfoTop(S) (S).T[(S).TOP]

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmptyTower(Tower *S);
/* I.S. sembarang; */
/* F.S. Membuat sebuah Tower S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 0.. MaxEl */
/* Ciri Tower kosong : TOP bernilai Nil */

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptyTower(Tower S);
/* Mengirim true jika Tower kosong: lihat definisi di atas */
boolean IsFullTower(Tower S);
/* Mengirim true jika tabel penampung nilai elemen Tower penuh */

/* ************ Menambahkan sebuah elemen ke Tower ************ */
void PushTower(Tower * S, infotype X);
/* Menambahkan X sebagai elemen Tower S. */
/* I.S. S mungkin kosong, tabel penampung elemen Tower TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */

/* ************ Menghapus sebuah elemen Tower ************ */
void PopTower(Tower * S, infotype* X);
/* Menghapus X dari Tower S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */

#endif
