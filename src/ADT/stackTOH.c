#include <stdio.h>
#include "stackTOH.h"

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */

/* I.S. sembarang; */
/* F.S. Membuat sebuah Tower S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 0.. MaxEl */
/* Ciri Tower kosong : TOP bernilai Nil */
void CreateEmptyTower(Tower *S){
        Top(*S) = Nil;
        for (int i = 0; i < MaxEl; i++){
            (*S).T[i] = Nil;
        }
}
/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptyTower(Tower S){
    return (Top(S) == Nil);
}
/* Mengirim true jika Tower kosong: lihat definisi di atas */
boolean IsFullTower(Tower S){
    return (Top(S) == (MaxEl - 1));
}
/* Mengirim true jika tabel penampung nilai elemen Tower penuh */

/* ************ Menambahkan sebuah elemen ke Tower ************ */
void PushTower(Tower * S, disk X){
    if (IsEmptyTower(*S)){
        Top(*S) = 0;
    } else {
        Top(*S)++;
    }
    InfoTop(*S) = X;
}
/* Menambahkan X sebagai elemen Tower S. */
/* I.S. S mungkin kosong, tabel penampung elemen Tower TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */

/* ************ Menghapus sebuah elemen Tower ************ */
void PopTower(Tower * S, disk* X){
    *X = InfoTop(*S);
    InfoTop(*S) = Nil;
    if (Top(*S) == 0){
        Top(*S) = Nil;
    } else {
       Top(*S)--;
    }
}
/* Menghapus X dari Tower S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */