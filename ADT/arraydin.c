#include "arraydin.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * Konstruktor
 * I.S. sembarang
 * F.S. Terbentuk ArrayDin kosong dengan ukuran InitialSize
 */
ArrayDin MakeArrayDin()
{
  ArrayDin array;
  array.A = (ElType *)malloc(InitialSize * sizeof(ElType));
  array.Capacity = InitialSize;
  array.Neff = 0;
  return array;
}

/**
 * Destruktor
 * I.S. ArrayDin terdefinisi
 * F.S. array->A terdealokasi
 */
void DeallocateArrayDin(ArrayDin *array)
{
  free(array->A);
}

/**
 * Fungsi untuk mengetahui apakah suatu array kosong.
 * Prekondisi: array terdefinisi
 */
boolean IsEmpty(ArrayDin array)
{
  return (Length(array) == 0);
}

/**
 * Fungsi untuk mendapatkan banyaknya elemen efektif array, 0 jika tabel kosong.
 * Prekondisi: array terdefinisi
 */
int Length(ArrayDin array)
{
  return array.Neff;
}

/**
 * Mengembalikan elemen array L yang ke-I (indeks lojik).
 * Prekondisi: array tidak kosong, i di antara 0..Length(array).
 */
ElType Get(ArrayDin array, IdxType i)
{
  return array.A[i];
}

/**
 * Fungsi untuk mendapatkan kapasitas yang tersedia.
 * Prekondisi: array terdefinisi
 */
int GetCapacity(ArrayDin array)
{
  return array.Capacity;
}

/**
 * Fungsi untuk menambahkan elemen baru di index ke-i
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void InsertAt(ArrayDin *array, ElType el, IdxType i)
{
  int len = Length(*array);
  int cap = GetCapacity(*array);
  int a;
  ElType *arr;

  if (len == cap)
  {
    int desired = cap + InitialSize;
    arr = (ElType *)malloc(desired * sizeof(ElType));
    for (a = 0; a < len; a++)
    {
      arr[a] = Get(*array, a);
    }
    free(array->A);
    array->A = arr;
    array->Capacity = desired;
  }
  for (a = len - 1; a >= i; a--)
  {
    array->A[a + 1] = array->A[a];
  }
  array->A[i] = el;
  array->Neff++;
}

/**
 * Fungsi untuk menghapus elemen di index ke-i ArrayDin
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void DeleteAt(ArrayDin *array, IdxType i)
{
  int j = i;
  for (j; j < array->Neff - 1; j++)
  {
    array->A[j] = array->A[j + 1];
  }
  array->Neff--;
}