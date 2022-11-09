#ifndef COBA_H
#define COBA_H

#include "ADT/mesinkata.h"
#include "ADT/mesinkalimat.h"
#include "boolean.h"

char *readQ();
/* I.S. : Sembarang
   F.S. : Mengembalikan string yang sudah diinputkan
   Proses : Membaca string yang sudah diinputkan */

boolean strcompare(char *str1, char *str2);

int stringLength(char *str);

char *wordToString(Word word);
/* I.S. : Sembarang
   F.S. : Mengembalika string dari word
   Proses : Mengembalikan string dari word */

char *sentenceToString(Sentence sentence);

int wordToInt(Word word);
/* I.S. : Sembarang
   F.S. : Mengembalikan integer dari word
   Proses : Mengembalikan integer dari word */

int sentenceToInt(Sentence sentence);

#endif