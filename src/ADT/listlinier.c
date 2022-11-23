#include <stdio.h>
#include "listlinier.h"

/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L)
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
        if (Info(p) == X)
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
    if (IsEmpty(*L))
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
    if (IsEmpty(*L))
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

/*** Prekondisi untuk Max/Min/rata-rata : List tidak kosong ***/
infotype Max (List L)
/* Mengirimkan nilai info(P) yang maksimum */
{
    address p = First(L);
    infotype max = Info(p);
    while (p != Nil)
    {
        if (Info(p) > max)
        {
            max = Info(p);
        }
        p = Next(p);
    }
    return max;    
}

address AdrMax (List L)
/* Mengirimkan address P, dengan info(P) yang bernilai maksimum */
{
    return (Search(L, Max(L)));
}

infotype Min (List L)
/* Mengirimkan nilai info(P) yang minimum */
{
    address p = First(L);
    infotype min = Info(p);
    while (p != Nil)
    {
        if (Info(p) < min)
        {
            min = Info(p);
        }
        p = Next(p);
    }
    return min;    
}

address AdrMin (List L)
/* Mengirimkan address P, dengan info(P) yang bernilai minimum */
{
    return (Search(L, Min(L)));
}

float Average (List L)
/* Mengirimkan nilai rata-rata info(P) */
{
    infotype sum = 0;
    int count = 0;
    float avg;
    address p = First(L);
    while (p != Nil)
    {
        sum += Info(p);
        count++;
        p = Next(p);
    }
    avg = (float) sum / (float) count;
    return avg;
}

/****************** PROSES TERHADAP LIST ******************/

void InversList (List *L)
/* I.S. sembarang. */
/* F.S. elemen list dibalik : */
/* Elemen terakhir menjadi elemen pertama, dan seterusnya. */
/* Membalik elemen list, tanpa melakukan alokasi/dealokasi. */
{
    address prev = Nil;
    address cur = First(*L);
    address next = Next(cur);
    while (cur != Nil)
    {
        Next(cur) = prev;
        prev = cur;
        cur = next;
        if (next != Nil)
        {
            next = Next(next);
        }
    }
    First(*L) = prev;
}

void Konkat1 (List *L1, List *L2, List *L3)
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2    */
/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */
/* dan L1 serta L2 menjadi list kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */
{
    First(*L3) = First(*L1);
    InsertLast(L3, First(*L2));
    First(*L1) = Nil;
    First(*L2) = Nil;
}

int main()
{
    List L;
    infotype val;
    CreateEmpty(&L);
    scanf("%d", &val);
    while((val >= 0) && (val <= 100))
    {
        InsVLast(&L, val);
        scanf("%d", &val);
    }

    if(IsEmpty(L))
    {
        printf("Daftar nilai kosong\n");
    }
    else
    {
        printf("%d\n", NbElmt(L));
        printf("%d\n", Max(L));
        printf("%d\n", Min(L));
        printf("%.2f\n", Average(L));
        PrintInfo(L);
        printf("\n");
        InversList(&L);
        PrintInfo(L);
        printf("\n");
    }
}