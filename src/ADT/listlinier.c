#include <stdio.h>
#include "listlinier.h"

/****************** TEST LIST KOSONG ******************/
boolean IsEmptyListLinier (List L)
/* Mengirim true jika list kosong */
{
    return (First(L) == Niln);
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L)
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
{
    First(*L) = Niln;
}

/****************** Manajemen Memori ******************/
addressLinked Alokasi (infotypeLinked X)
/* Mengirimkan addressLinked hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addressLinked tidak Niln, dan misalnya */
/* menghasilkan P, maka info(P)=X, Next(P)=Niln */
/* Jika alokasi gagal, mengirimkan Niln */
{
    addressLinked p = (addressLinked) malloc (sizeof(ElmtList));
    if (p != Niln)
    {
        Info(p) = X;
        Next(p) = Niln;
        return p;
    }
    else
    {
        return Niln;
    }
}

void Dealokasi (addressLinked *P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addressLinked P */
{
    free(*P);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
addressLinked Search (List L, infotypeLinked X)
/* Mencari apakah ada elemen list dengan info(P)= X */
/* Jika ada, mengirimkan addressLinked elemen tersebut. */
/* Jika tidak ada, mengirimkan Niln */
{
    addressLinked p = First(L);
    boolean found = false;
    while ((p != Niln) && !found)
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
void InsVFirst (List *L, infotypeLinked X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
{
    addressLinked p = Alokasi(X);
    if (p != Niln)
    {
        Next(p) = First(*L);
        First(*L) = p;
    }
}

void InsVLast (List *L, infotypeLinked X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
    addressLinked p, last;
    if (IsEmptyListLinier(*L))
    {
        InsVFirst(L, X);
    }
    else
    {
        p = Alokasi(X);
        if (p != Niln)
        {
            last = First(*L);
            while (Next(last) != Niln)
            {
                last = Next(last);
            }
            Next(last) = p;
        }
    }
}

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotypeLinked *X)
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
{
    addressLinked p = First(*L);
    (*X) = Info(p);
    First(*L) = Next(p);
    Next(p) = Niln;
    Dealokasi(&p);
}

void DelVLast (List *L, infotypeLinked *X)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
{
    addressLinked p, loc;
    p = First(*L);
    loc = Niln;
    while (Next(p) != Niln)
    {
        loc = p;
        p = Next(p);
    }
    // Next(p) == Niln
    if (loc == Niln)
    {
        First(*L) = Niln;
    }
    else
    {
        Next(loc) = Niln;
    }
    (*X) = Info(p);
    Dealokasi(&p);
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirstList (List *L, addressLinked P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-addressLinked P sebagai elemen pertama */
{
    Next(P) = First(*L);
    First(*L) = P;
}

void InsertAfter (List *L, addressLinked P, addressLinked Prec)
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{
    Next(P) = Next(Prec);
    Next(Prec) = P;
}

void InsertLastList (List *L, addressLinked P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{
    addressLinked last;
    if (IsEmptyListLinier(*L))
    {
        InsertFirstList(L,P);
    }
    else
    {
        last = First(*L);
        while (Next(last) != Niln)
        {
            last = Next(last);
        }
        Next(last) = P;
    }
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, addressLinked *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
{
    (*P) = First(*L);
    First(*L) = Next(*P);
    Next(*P) = Niln;
}

void DelP (List *L, infotypeLinked X)
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddressLinked P, dengan info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
{
    addressLinked p, loc;
    p = Search(*L, X);
    loc = First(*L);
    if (p != Niln)
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

void DelLast (List *L, addressLinked *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
{
    (*P) = First(*L);
    addressLinked loc = Niln;
    while (Next(*P) != Niln)
    {
        loc = (*P);
        (*P) = Next(*P);
    }
    if (loc == Niln)
    {
        First(*L) = Niln;
    }
    else
    {
        Next(loc) = Niln;
    }
}

/* jika ada */
void DelAfter (List *L, addressLinked *Pdel, addressLinked Prec)
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
    (*Pdel) = Next(Prec);
    Next(Prec) = Next(*Pdel);
    Next(*Pdel) = Niln;
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (List L)
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
    addressLinked p = First(L);
    if (p == Niln) // list kosong
    {
        printf("[]");
    }
    else
    {
        printf("[");
        while(p != Niln)
        {
            displayPoint(Info(p));
            if (Next(p) != Niln)
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
    addressLinked p = First(L);
    while (p != Niln)
    {
        count++;
        p = Next(p);
    }
    return count;
}