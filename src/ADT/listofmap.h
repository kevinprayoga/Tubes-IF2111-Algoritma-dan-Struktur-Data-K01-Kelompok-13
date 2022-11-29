#ifndef listofmap_H
#define listofmap_H
#include "../boolean.h"

#define Nilz 0
#define MaxEl 100
#define Undefined -999

typedef char *keytype;
typedef int valuetype;
typedef int address;

typedef struct
{
  keytype Key;
  valuetype Value;
} infotype;

typedef struct
{
  infotype Elements[MaxEl];
  address Count;
} Map;

typedef struct
{
  Map list[MaxEl];
  address total;
} ListMap;


/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateEmptyListMap(ListMap *L);
/* I.S. Sembarang */
/* F.S. Membuat sebuah ListMap L kosong berkapasitas MaxEl */
/* Ciri ListMap kosong : count bernilai Nil */

void CreateEmptyMap(ListMap *L);
/* I.S. Sembarang */
/* F.S. Membuat sebuah Map kosong berkapasitas MaxEl dari ListMap L */
/* Ciri Map kosong : count bernilai Nil */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmptyList(ListMap L);
/* Mengirim true jika ListMap L kosong*/
/* Ciri ListMap kosong : total bernilai Nil */

boolean IsEmptyMap(ListMap L, address num);
/* Mengirim true jika Map di ListMap L dengan address num kosong */
/* Ciri Map kosong : count bernilai Nil di ListMap L dengan address num */

boolean IsFullList(ListMap L);
/* Mengirim true jika ListMap L penuh */
/* Ciri ListMap penuh : total bernilai MaxEl */

boolean IsFullMap(ListMap L, address num);
/* Mengirim true jika Map di ListMap L dengan address num penuh */
/* Ciri Map penuh : count bernilai MaxEl */

/* ********** Operator Dasar Map ********* */
valuetype Value(ListMap L, keytype k, address num);
/* Mengembalikan nilai value dengan key k dari Map sebuah ListMap L ber address num */
/* Jika tidak ada key k pada Map dengan ListMap L ber address num, akan mengembalikan Undefined */

void InsertMap(ListMap *L, keytype k, valuetype v, address num);
/* Menambahkan Elmt sebagai elemen Map dari sebuah ListMap L ber address num. */
/* I.S. Map mungkin kosong dari sebuah ListMap L, Map tidak penuh
        Map mungkin sudah beranggotakan v dengan key k dari sebuah ListMap */
/* F.S. v menjadi anggota dari Map dengan key k dari sebuah ListMap L ber address num. Jika k sudah ada, operasi tidak dilakukan */

void DeleteMap(ListMap *L, address num);
/* Menghapus Map dari ListMap L. */
/* I.S. L tidak kosong
        Map dengan address num mungkin anggota / bukan anggota dari ListMap L */
/* F.S. Map dengan address num bukan anggota dari L */

boolean IsMemberMap(ListMap L, keytype k, address num);
/* Mengembalikan true jika k adalah member dari L dan address num */

#endif