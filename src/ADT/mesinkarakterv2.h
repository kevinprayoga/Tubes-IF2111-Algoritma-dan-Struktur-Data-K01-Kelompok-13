/* File: mesinkarakterv2.h */
/* Definisi Mesin Karakter */

#ifndef __MESIN_KAR_V2_H_
#define __MESIN_KAR_V2_H_

#define boolean unsigned char
#define true 1
#define false 0

#define MARK '\n'
#define BLANK ' '
/* State Mesin */
extern char currentChar;
extern boolean EOP;

void STARTV2();
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   Pita baca diambil dari stdin.
   I.S. : sembarang
   F.S. : currentChar adalah karakter pertama pada pita
          Jika currentChar != MARK maka EOP akan padam (false)
          Jika currentChar = MARK maka EOP akan menyala (true) */

void ADVV2();
/* Pita dimajukan satu karakter.
   I.S. : Karakter pada jendela = currentChar, currentChar != MARK
   F.S. : currentChar adalah karakter berikutnya dari currentChar yang lama,
          currentChar mungkin = MARK
          Jika  currentChar = MARK maka EOP akan menyala (true) */

char GetCCV2();
/* Mengirimkan currentChar */

boolean IsEOPV2();
/* Mengirimkan true jika currentChar = MARK */

boolean CLOSE();
/* Menutup file pita */

#endif