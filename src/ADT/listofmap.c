#include "listofmap.h"
#include <stdio.h>
#include "../console.h"

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateEmptyListMap(ListMap *L)
{
  L->total = Nilz;
}

void CreateEmptyMap(ListMap *L)
{
  L->list[L->total].Count = Nilz;
  L->total++;
}
/* I.S. Sembarang */
/* F.S. Membuat sebuah Map M kosong berkapasitas MaxEl */
/* Ciri Map kosong : count bernilai Nil */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmptyList(ListMap L)
{
  return (L.total == Nilz);
}
/* Mengirim true jika Map M kosong*/
/* Ciri Map kosong : count bernilai Nil */

boolean IsEmptyMap(ListMap L, address num)
{
  if (!IsEmptyList(L))
  {
    return (L.list[num - 1].Count == Nilz);
  }
}
/* Mengirim true jika Map M kosong*/
/* Ciri Map kosong : count bernilai Nil */

boolean IsFullList(ListMap L)
{
  return (L.total == MaxEl);
}
/* Mengirim true jika Map M penuh */
/* Ciri Map penuh : count bernilai MaxEl */

boolean IsFullMap(ListMap L, address num)
{
  return (L.list[num - 1].Count == MaxEl);
}
/* Mengirim true jika Map M penuh */
/* Ciri Map penuh : count bernilai MaxEl */

/* ********** Operator Dasar Map ********* */
valuetype Value(ListMap L, keytype k, address num)
{
  int i = 0;
  boolean found = false;
  while ((i < L.list[num - 1].Count) && !(found))
  {
    if (strcompare(k, L.list[num - 1].Elements[i].Key))
    {
      found = true;
    }
    else
    {
      i++;
    }
  }
  if (found)
  {
    return L.list[num - 1].Elements[i].Value;
  }
  else
  {
    return Undefined;
  }
}
/* Mengembalikan nilai value dengan key k dari M */
/* Jika tidak ada key k pada M, akan mengembalikan Undefined */

void InsertMap(ListMap *L, keytype k, valuetype v, address num)
{
  if (!IsMemberMap(*L, k, num))
  {
    int i = 0;
    while (v <= L->list[num - 1].Elements[i].Value && i < L->list[num - 1].Count)
    {
      i++;
    }
    for (int j = L->list[num - 1].Count; j > i; j--)
    {
      L->list[num - 1].Elements[j].Key = L->list[num - 1].Elements[j - 1].Key;
      L->list[num - 1].Elements[j].Value = L->list[num - 1].Elements[j - 1].Value;
    }
    L->list[num - 1].Elements[i].Key = k;
    L->list[num - 1].Elements[i].Value = v;
    L->list[num - 1].Count++;
  }
}
/* Menambahkan Elmt sebagai elemen Map M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan */

void DeleteMap(ListMap *L, address num)
{
  if (num < L->total)
  {
    for (int i = num - 1; i < L->total - 1; i++)
    {
      L->list[i] = L->list[i + 1];
    }
  }
  int len = L->list[num - 1].Count;
  for (int i = 0; i < len; i++)
  {
    L->list[num - 1].Count--;
  }
  L->total--;
}
/* Menghapus Elmt dari Map M. */
/* I.S. M tidak kosong
        element dengan key k mungkin anggota / bukan anggota dari M */
/* F.S. element dengan key k bukan anggota dari M */

boolean IsMemberMap(ListMap L, keytype k, address num)
{
  valuetype v = Value(L, k, num);
  return (v != Undefined);
}
/* Mengembalikan true jika k adalah member dari M */