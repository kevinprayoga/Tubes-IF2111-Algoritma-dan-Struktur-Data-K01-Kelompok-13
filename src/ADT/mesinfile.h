/* File: mesinkarakter.h */
/* Definisi Mesin Karakter */

#ifndef __MESIN_FILE_H_
#define __MESIN_FILE_H_

#include "mesinkar.h"
#include "mesinkata.h"
#include "../boolean.h"

void STARTFILE(char *filename);
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : sembarang
   F.S. : CC adalah karakter pertama pada pita
          Jika CC != MARK, EOP akan padam (false)
          Jika CC = MARK, EOP akan menyala (true) */

void ADVFILE();
/* Pita dimajukan satu karakter.
   I.S. : Karakter pada jendela =
          CC, CC != MARK
   F.S. : CC adalah karakter berikutnya dari CC yang lama,
          CC mungkin = MARK
          Jika  CC = MARK, EOP akan menyala (true) */

void IgnoreNewLine();
/* Mengabaikan karakter newline */

void IgnoreBlank();

void ADVWORDFILE();
/* Mengambil kata dari pita */

void ADVWORDFILEWOBLANK();

void CopyWordFile();
/* Menyalin kata dari pita ke currentWord */

void CopyWordFileWOBlank();

#endif