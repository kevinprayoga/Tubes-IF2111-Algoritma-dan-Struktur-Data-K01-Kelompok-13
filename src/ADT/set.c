#include <stdio.h>
#include "set.h"

/* *** Konstruktor/Kreator *** */
void CreateEmptySetChar(SetChar *S)
/* I.S. Sembarang */
/* F.S. Membuat sebuah Set S kosong berkapasitas MaxEl */
/* Ciri Set kosong : count bernilai Nil */
{
    (*S).Count = Nil;
}

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmptySetChar(SetChar S)
/* Mengirim true jika Set S kosong*/
/* Ciri Set kosong : count bernilai Nil */
{
    return (S.Count == Nil);
}

boolean IsFullSetChar(SetChar S)
/* Mengirim true jika Set S penuh */
/* Ciri Set penuh : count bernilai MaxEl */
{
    return (S.Count == MaxEl);
}

/* ********** Operator Dasar Set ********* */
void InsertSetChar(SetChar *S, infoChar Elmt)
/* Menambahkan Elmt sebagai elemen Set S. */
/* I.S. S mungkin kosong, S tidak penuh
        S mungkin sudah beranggotakan Elmt */
/* F.S. Elmt menjadi anggota dari S. Jika Elmt sudah merupakan anggota, operasi tidak dilakukan */
{
    if (IsEmptySetChar(*S)){
        (*S).Elements[0] = Elmt;
    } else {
        if (!(IsMemberSetChar(*S, Elmt))){
            (*S).Elements[(*S).Count] = Elmt;
        }
    }
    (*S).Count++;
}

void DeleteSetChar(SetChar *S, infoChar Elmt)
/* Menghapus Elmt dari Set S. */
/* I.S. S tidak kosong
        Elmt mungkin anggota / bukan anggota dari S */
/* F.S. Elmt bukan anggota dari S */
{
    boolean found = false;
    int i = 0;

    while (i < (*S).Count && found == false){
        if ((*S).Elements[i] == Elmt){
            found = true;
        } else{
            i++;  
        }
        
    }
    if (found == true){
        while(i < ((*S).Count - 1)){
            (*S).Elements[i] = (*S).Elements[i+1];
            i++;
        }
        (*S).Count--;
    }
}

boolean IsMemberSetChar(SetChar S, infoChar Elmt){
    boolean found = false;
    int i = 0;

    while (i < (S).Count && found == false){
        if ((S).Elements[i] == Elmt){
            found = true;
        } else{
            i++;  
        }
    }
    return found;
}
/* Mengembalikan true jika Elmt adalah member dari S */

/* *** Konstruktor/Kreator *** */
void CreateEmptySetStr(SetStr *S)
/* I.S. Sembarang */
/* F.S. Membuat sebuah Set S kosong berkapasitas MaxEl */
/* Ciri Set kosong : count bernilai Nil */
{
    (*S).Count = Nil;
}

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmptySetStr(SetStr S)
/* Mengirim true jika Set S kosong*/
/* Ciri Set kosong : count bernilai Nil */
{
    return (S.Count == Nil);
}

boolean IsFullSetStr(SetStr S)
/* Mengirim true jika Set S penuh */
/* Ciri Set penuh : count bernilai MaxEl */
{
    return (S.Count == MaxEl);
}

/* ********** Operator Dasar Set ********* */
void InsertSetStr(SetStr *S, infoStr Elmt)
/* Menambahkan Elmt sebagai elemen Set S. */
/* I.S. S mungkin kosong, S tidak penuh
        S mungkin sudah beranggotakan Elmt */
/* F.S. Elmt menjadi anggota dari S. Jika Elmt sudah merupakan anggota, operasi tidak dilakukan */
{
    if (IsEmptySetStr(*S)){
        (*S).Elements[0] = Elmt;
    } else {
        if (!(IsMemberSetStr(*S, Elmt))){
            (*S).Elements[(*S).Count] = Elmt;
        }
    }
    (*S).Count++;
}

void DeleteSetStr(SetStr *S, infoStr Elmt)
/* Menghapus Elmt dari Set S. */
/* I.S. S tidak kosong
        Elmt mungkin anggota / bukan anggota dari S */
/* F.S. Elmt bukan anggota dari S */
{
    boolean found = false;
    int i = 0;

    while (i < (*S).Count && found == false){
        if ((*S).Elements[i] == Elmt){
            found = true;
        } else{
            i++;  
        }
        
    }
    if (found == true){
        while(i < ((*S).Count - 1)){
            (*S).Elements[i] = (*S).Elements[i+1];
            i++;
        }
        (*S).Count--;
    }
}

boolean IsMemberSetStr(SetStr S, infoStr Elmt){
    boolean found = false;
    int i = 0;

    while (i < (S).Count && found == false){
        if (strcomp(S.Elements[i], Elmt)){
            found = true;
        } else{
            i++;  
        }
    }
    return found;
}
/* Mengembalikan true jika Elmt adalah member dari S */

boolean IsMemberChar(char* Elmt, char cc){
    boolean found = false;
    int i = 0;

    while (i < strlen(Elmt) && found == false){
        if (Elmt[i] == cc){
            found = true;
        } else{
            i++;  
        }
    }
    return found;
}

int strlen(char* Elmt){
    int i = 0;
    while (Elmt[i] != '\0'){
        i++;
    }
    return i;
}

boolean strcomp(char *Elmt1, char *Elmt2)
{
  int i = 0;
  boolean found = false;
  if (strlen(Elmt1) != strlen(Elmt2))
  {
    return found;
  }
  else
  {
    while (!found && i < strlen(Elmt1))
    {
      if (Elmt1[i] != Elmt2[i])
      {
        return found;
      }
      i++;
    }
    return !found;
  }
}