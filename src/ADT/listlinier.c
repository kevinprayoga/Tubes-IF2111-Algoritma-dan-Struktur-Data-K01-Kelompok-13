#include <stdio.h>
#include "listlinier.h"

/****************** TEST LIST KOSONG ******************/
boolean IsEmptyListLinier (List L)
/* Mengirim true jika list kosong */
{
    return (First(L) == Nil);
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L)
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
{
    First(*L) = Nil;
}

/****************** Manajemen Memori ******************/
address Alokasi (infotype X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
    address p = (address) malloc (sizeof(ElmtList));
    if (p != Nil)
    {
        Info(p) = X;
        Next(p) = Nil;
        return p;
    }
    else
    {
        return Nil;
    }
}

void Dealokasi (address *P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
{
    free(*P);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, infotype X)
/* Mencari apakah ada elemen list dengan info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
{
    address p = First(L);
    boolean found = false;
    while ((p != Nil) && !found)
    {
        if ((InfoX(p) == ABSIS(X)) && (InfoY(p) == ORDINAT(X)))
        {
            found = true;
        }
        else
        {
            p = Next(p);
        }
    }
    return p;
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
{
    address p = Alokasi(X);
    if (p != Nil)
    {
        Next(p) = First(*L);
        First(*L) = p;
    }
}

void InsVLast (List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
    address p, last;
    if (IsEmptyListLinier(*L))
    {
        InsVFirst(L, X);
    }
    else
    {
        p = Alokasi(X);
        if (p != Nil)
        {
            last = First(*L);
            while (Next(last) != Nil)
            {
                last = Next(last);
            }
            Next(last) = p;
        }
    }
}

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype *X)
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
{
    address p = First(*L);
    (*X) = Info(p);
    First(*L) = Next(p);
    Next(p) = Nil;
    Dealokasi(&p);
}

void DelVLast (List *L, infotype *X)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
{
    address p, loc;
    p = First(*L);
    loc = Nil;
    while (Next(p) != Nil)
    {
        loc = p;
        p = Next(p);
    }
    // Next(p) == Nil
    if (loc == Nil)
    {
        First(*L) = Nil;
    }
    else
    {
        Next(loc) = Nil;
    }
    (*X) = Info(p);
    Dealokasi(&p);
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
{
    Next(P) = First(*L);
    First(*L) = P;
}

void InsertAfter (List *L, address P, address Prec)
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{
    Next(P) = Next(Prec);
    Next(Prec) = P;
}

void InsertLast (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{
    address last;
    if (IsEmptyListLinier(*L))
    {
        InsertFirst(L,P);
    }
    else
    {
        last = First(*L);
        while (Next(last) != Nil)
        {
            last = Next(last);
        }
        Next(last) = P;
    }
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
{
    (*P) = First(*L);
    First(*L) = Next(*P);
    Next(*P) = Nil;
}

void DelP (List *L, infotype X)
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
{
    address p, loc;
    p = Search(*L, X);
    loc = First(*L);
    if (p != Nil)
    {
        if (NbElmt(*L) == 1)
        {
            DelFirst(L, &p);
        }
        else
        {
            while (Next(loc) != p)
            {
                loc = Next(loc);
            }
            DelAfter(L, &p, loc);
        }
    }
    Dealokasi(&p);
}

void DelLast (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
{
    (*P) = First(*L);
    address loc = Nil;
    while (Next(*P) != Nil)
    {
        loc = (*P);
        (*P) = Next(*P);
    }
    if (loc == Nil)
    {
        First(*L) = Nil;
    }
    else
    {
        Next(loc) = Nil;
    }
}

/* jika ada */
void DelAfter (List *L, address *Pdel, address Prec)
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
    (*Pdel) = Next(Prec);
    Next(Prec) = Next(*Pdel);
    Next(*Pdel) = Nil;
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (List L)
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
    address p = First(L);
    if (p == Nil) // list kosong
    {
        printf("[]");
    }
    else
    {
        printf("[");
        while(p != Nil)
        {
            printf("%d", Info(p));
            if (Next(p) != Nil)
            {
                printf(",");
            }
            p = Next(p);
        }
        printf("]");
    }
}

int NbElmt (List L)
/* Mengirimkan banyaknya elemen list mengirimkan 0 jika list kosong */
{
    int count = 0;
    address p = First(L);
    while (p != Nil)
    {
        count++;
        p = Next(p);
    }
    return count;
}