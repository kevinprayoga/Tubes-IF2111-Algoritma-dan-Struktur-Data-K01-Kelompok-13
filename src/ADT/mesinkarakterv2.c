#include <stdio.h>
#include "mesinkarakterv2.h"

/* State Mesin */
char currentChar;
boolean EOP;

static FILE *pita;
static int retval;

void STARTV2()
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   Pita baca diambil dari stdin.
   I.S. : sembarang
   F.S. : currentChar adalah karakter pertama pada pita
          Jika currentChar != MARK maka EOP akan padam (false)
          Jika currentChar = MARK maka EOP akan menyala (true) */
{
  pita = stdin;
  ADVV2();
}

void ADVV2()
/* Pita dimajukan satu karakter.
   I.S. : Karakter pada jendela = currentChar, currentChar != MARK
   F.S. : currentChar adalah karakter berikutnya dari currentChar yang lama,
          currentChar mungkin = MARK
          Jika  currentChar = MARK maka EOP akan menyala (true) */
{
  retval = fscanf(pita, "%c", &currentChar);
}

char GetCCV2()
/* Mengirimkan currentChar */
{
  return (currentChar);
}

boolean IsEOPV2()
/* Mengirimkan true jika currentChar = MARK */
{
  return (currentChar == MARK);
}

boolean CLOSE()
/* Menutup file pita */
{
    fclose(pita);
}