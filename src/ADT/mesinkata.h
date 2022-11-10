#ifndef __MESINKATA_H__
#define __MESINKATA_H__

#include "mesinkar.h"

#include "../boolean.h"

#define NMax 50
#define BLANK ' '

typedef struct
{
  char TabWord[NMax]; /* container penyimpan kata, indeks yang dipakai [0..NMax-1] */
  int Length;
} Word;

/* State Mesin Kata */
extern boolean EndWord;
extern Word currentWord;

void STARTWORD();
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : sembarang
   F.S. : currentWord adalah kata pertama pada pita
          EndWord = false; currentWord.Length > 0 */

void ADVWORD();
/* Pita dimajukan satu kata.
   I.S. : currentWord adalah kata yang sudah diakuisisi,
          currentWord.Length > 0
   F.S. : currentWord adalah kata berikutnya, mungkin MARK
          Jika currentWord = MARK maka EndWord = true */

void CopyWord();
/* I.S. : currentWord.Length > 0
   F.S. : currentWord adalah kata yang sudah diakuisisi,
          currentWord.Length > 0 */

#endif