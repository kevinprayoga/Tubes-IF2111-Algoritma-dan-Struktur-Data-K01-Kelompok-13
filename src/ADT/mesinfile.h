/* File: mesinkarakter.h */
/* Definisi Mesin Karakter */

#ifndef __MESIN_FILE_H_
#define __MESIN_FILE_H_

#include "mesinkar.h"
#include "mesinkata.h"

#define boolean unsigned char
#define true 1
#define false 0

void STARTFILE(char *filename);
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   Pita baca diambil dari stdin.
   I.S. : sembarang
   F.S. : currentChar adalah karakter pertama pada pita
          Jika currentChar != MARK maka EOP akan padam (false)
          Jika currentChar = MARK maka EOP akan menyala (true) */

void ADVFILE();
/* Pita dimajukan satu karakter.
   I.S. : Karakter pada jendela = currentChar, currentChar != MARK
   F.S. : currentChar adalah karakter berikutnya dari currentChar yang lama,
          currentChar mungkin = MARK
          Jika  currentChar = MARK maka EOP akan menyala (true) */

void IgnoreNewLine();

void ADVWORDFILE();

void CopyWordFile();

#endif