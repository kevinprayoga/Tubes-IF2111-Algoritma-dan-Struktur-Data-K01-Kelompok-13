#ifndef COBA_H
#define COBA_H

#include "ADT/mesinkata.h"
#include "ADT/mesinkar.h"
#include "ADT/queue.h"
#include "ADT/arraydin.h"
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

int wordToInt(Word word);
/* I.S. : Sembarang
   F.S. : Mengembalikan integer dari word
   Proses : Mengembalikan integer dari word */

char *firststring(char *command);

char *secondstring(char *command);

int space_char(char *str);

char *strconcat(char *dest, char *src);

boolean isMemberQ(Queue q, char* val);

int strToInt(char *str);

boolean isNum(char* str);

void loading();

#endif