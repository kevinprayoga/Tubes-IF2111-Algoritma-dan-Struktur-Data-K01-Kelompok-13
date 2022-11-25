#include <stdio.h>
#include "stackTOH.h"

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */

/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 0.. MaxEl */
/* Ciri stack kosong : TOP bernilai Nil */
void CreateEmptyStack(Stack *S){
        Top(*S) = Nil;
        for (int i = 0; i < MaxEl; i++){
            (*S).T[i] = Nil;
        }
}
/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptyStack(Stack S){
    return (Top(S) == Nil);
}
/* Mengirim true jika Stack kosong: lihat definisi di atas */
boolean IsFullStack(Stack S){
    return (Top(S) == (MaxEl - 1));
}
/* Mengirim true jika tabel penampung nilai elemen stack penuh */

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push(Stack * S, infotype X){
    if (IsEmptyStack(*S)){
        Top(*S) = 0;
    } else {
        Top(*S)++;
    }
    InfoTop(*S) = X;
}
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */

/* ************ Menghapus sebuah elemen Stack ************ */
void Pop(Stack * S, infotype* X){
    *X = InfoTop(*S);
    InfoTop(*S) = Nil;
    if (Top(*S) == 0){
        Top(*S) = Nil;
    } else {
       Top(*S)--;
    }
}
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */