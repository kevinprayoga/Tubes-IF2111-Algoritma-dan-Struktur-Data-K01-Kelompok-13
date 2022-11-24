#include <stdio.h>
#include "stack.h"

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmptyStack(Stack *S)
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 0.. MaxEl */
/* Ciri stack kosong : TOP bernilai Nil */
{
  Top(*S) = Nil;
}

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptyStack(Stack S)
/* Mengirim true jika Stack kosong: lihat definisi di atas */
{
  return Top(S) == Nil;
}
boolean IsFullStack(Stack S)
/* Mengirim true jika tabel penampung nilai elemen stack penuh */
{
  return Top(S) == MaxEl - 1;
}

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push(Stack *S, info X)
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */
{
  Top(*S)++;
  InfoTop(*S) = X;
}

/* ************ Menghapus sebuah elemen Stack ************ */
void Pop(Stack *S, info *X)
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
{
  *X = InfoTop(*S);
  Top(*S)--;
}

void printStack(Stack *S, int command)
/* Menampilkan elemen Stack S berdasarkan jumlah command yang ingin ditampilkan. */
/* I.S. S mungkin kosong */
/* F.S. Jika Stack S tidak kosong maka akan print nilai Stack */
{
  int i = 1;
  info val;
  Stack s1;
  CreateEmptyStack(&s1);
  s1 = *S;
  while (i <= command && !IsEmptyStack(s1))
  {
    printf("%d. %s\n", i, InfoTop(s1));
    Pop(&s1, &val);
    i++;
  }
}

int countStack(Stack S)
/* Mengembalikan jumlah alamat dalam Stack S */
{
  info val;
  Stack s1;
  CreateEmptyStack(&s1);
  s1 = S;
  int count = 0;
  while (!IsEmptyStack(s1))
  {
    Pop(&s1, &val);
    count++;
  }
  return count;
}