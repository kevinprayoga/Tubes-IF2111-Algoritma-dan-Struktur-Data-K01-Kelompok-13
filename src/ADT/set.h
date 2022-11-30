#ifndef set_H
#define set_H
#include <stdio.h>
#include "../boolean.h"

/* MODUL Set
Deklarasi stack yang dengan implementasi array eksplisit-statik rata kiri
*/

#define Nil 0
#define MaxEl 100

typedef char* infoStr;
typedef char infoChar;
typedef int address;

typedef struct
{
    infoStr Elements[MaxEl];
    address Count;
} SetStr;
 
typedef struct setChar
{
    infoChar Elements[MaxEl];
    address Count;
} SetChar;


/* Definisi SetChar S kosong : S.Count = Nil */
/* S.Count = jumlah element SetChar */
/* S.Elements = tempat penyimpanan element SetChar */

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateEmptySetChar(SetChar *S);
/* I.S. Sembarang */
/* F.S. Membuat sebuah SetChar S kosong berkapasitas MaxEl */
/* Ciri SetChar kosong : count bernilai Nil */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmptySetChar(SetChar S);
/* Mengirim true jika SetChar S kosong*/
/* Ciri SetChar kosong : count bernilai Nil */

boolean IsFullSetChar(SetChar S);
/* Mengirim true jika SetChar S penuh */
/* Ciri SetChar penuh : count bernilai MaxEl */

/* ********** Operator Dasar SetChar ********* */
void InsertSetChar(SetChar *S, infoChar Elmt);
/* Menambahkan Elmt sebagai elemen SetChar S. */
/* I.S. S mungkin kosong, S tidak penuh
        S mungkin sudah beranggotakan Elmt */
/* F.S. Elmt menjadi anggota dari S. Jika Elmt sudah merupakan anggota, operasi tidak dilakukan */

void DeleteSetChar(SetChar *S, infoChar Elmt);
/* Menghapus Elmt dari SetChar S. */
/* I.S. S tidak kosong
        Elmt mungkin anggota / bukan anggota dari S */
/* F.S. Elmt bukan anggota dari S */

boolean IsMemberSetChar(SetChar S, infoChar Elmt);
/* Mengembalikan true jika Elmt adalah member dari S */

void CreateEmptySetStr(SetStr *S);
/* I.S. Sembarang */
/* F.S. Membuat sebuah SetChar S kosong berkapasitas MaxEl */
/* Ciri SetChar kosong : count bernilai Nil */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmptySetStr(SetStr S);
/* Mengirim true jika SetChar S kosong*/
/* Ciri SetChar kosong : count bernilai Nil */

boolean IsFullSetStr(SetStr S);
/* Mengirim true jika SetChar S penuh */
/* Ciri SetChar penuh : count bernilai MaxEl */

/* ********** Operator Dasar SetChar ********* */
void InsertSetStr(SetStr *S, infoStr Elmt);
/* Menambahkan Elmt sebagai elemen SetChar S. */
/* I.S. S mungkin kosong, S tidak penuh
        S mungkin sudah beranggotakan Elmt */
/* F.S. Elmt menjadi anggota dari S. Jika Elmt sudah merupakan anggota, operasi tidak dilakukan */

void DeleteSetStr(SetStr *S, infoStr Elmt);
/* Menghapus Elmt dari SetChar S. */
/* I.S. S tidak kosong
        Elmt mungkin anggota / bukan anggota dari S */
/* F.S. Elmt bukan anggota dari S */

boolean IsMemberSetStr(SetStr S, infoStr Elmt);
/* Mengembalikan true jika Elmt adalah member dari S */

boolean IsMemberChar(char* Elmt, char cc);

int strlen(char* Elmt);
/* Mengembalikan panjang string s */

boolean strcomp(char *Elmt1, char *Elmt2);

#endif