/* File : listlinier.h */
/* contoh ADT list berkait dengan representasi fisik pointer  */
/* Representasi addressLinked dengan pointer */
/* infotypeLinked adalah integer */

#ifndef listlinier_H
#define listlinier_H

#include "point.h"
#include <stdlib.h>

// Boolean
#define boolean unsigned char
#define true 1
#define false 0

#define Niln NULL

typedef point infotypeLinked;
typedef struct tElmtlist *addressLinked;
typedef struct tElmtlist { 
	infotypeLinked info;
	addressLinked next;
} ElmtList;
typedef struct {
	addressLinked First;
} List;

/* Definisi list : */
/* List kosong : First(L) = Niln */
/* Setiap elemen dengan addressLinked P dapat diacu Info(P), Next(P) */
/* Elemen terakhir list : jika addressLinkednya Last, maka Next(Last)=Niln */
#define Info(P) (P)->info
#define InfoX(P) ABSIS(Info(P))
#define InfoY(P) ORDINAT(Info(P))
#define Next(P) (P)->next
#define First(L) ((L).First)

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmptyListLinier (List L);
/* Mengirim true jika list kosong */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L);
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */

/****************** Manajemen Memori ******************/
addressLinked Alokasi (infotypeLinked X);
/* Mengirimkan addressLinked hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addressLinked tidak Niln, dan misalnya */
/* menghasilkan P, maka info(P)=X, Next(P)=Niln */
/* Jika alokasi gagal, mengirimkan Niln */
void Dealokasi (addressLinked *P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addressLinked P */

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
addressLinked Search (List L, infotypeLinked X);
/* Mencari apakah ada elemen list dengan info(P)= X */
/* Jika ada, mengirimkan addressLinked elemen tersebut. */
/* Jika tidak ada, mengirimkan Niln */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotypeLinked X);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
void InsVLast (List *L, infotypeLinked X);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotypeLinked *X);
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
void DelVLast (List *L, infotypeLinked *X);
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirstList (List *L, addressLinked P);
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-addressLinked P sebagai elemen pertama */
void InsertAfter (List *L, addressLinked P, addressLinked Prec);
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
void InsertLastList (List *L, addressLinked P);
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, addressLinked *P);
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
void DelP (List *L, infotypeLinked X);
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddressLinked P, dengan info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
void DelLast (List *L, addressLinked *P);
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */
void DelAfter (List *L, addressLinked *Pdel, addressLinked Prec);
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (List L);
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
int NbElmt (List L);
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */

/*** Prekondisi untuk Max/Min/rata-rata : List tidak kosong ***/
infotypeLinked Max (List L);
/* Mengirimkan nilai info(P) yang maksimum */
addressLinked AdrMax (List L);
/* Mengirimkan addressLinked P, dengan info(P) yang bernilai maksimum */
infotypeLinked Min (List L);
/* Mengirimkan nilai info(P) yang minimum */
addressLinked AdrMin (List L);
/* Mengirimkan addressLinked P, dengan info(P) yang bernilai minimum */
float Average (List L);
/* Mengirimkan nilai rata-rata info(P) */

/****************** PROSES TERHADAP LIST ******************/

void InversList (List *L);
/* I.S. sembarang. */
/* F.S. elemen list dibalik : */
/* Elemen terakhir menjadi elemen pertama, dan seterusnya. */
/* Membalik elemen list, tanpa melakukan alokasi/dealokasi. */

void Konkat1 (List *L1, List *L2, List *L3);
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2    */
/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */
/* dan L1 serta L2 menjadi list kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */

#endif