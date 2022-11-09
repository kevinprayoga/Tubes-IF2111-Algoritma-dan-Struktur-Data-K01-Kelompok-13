#include <stdio.h>
#include "mesinfile.h"

static FILE *pita;
static int retval;

void STARTFILE(char *filename)
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   Pita baca diambil dari stdin.
   I.S. : sembarang
   F.S. : currentChar adalah karakter pertama pada pita
          Jika currentChar != MARK maka EOP akan padam (false)
          Jika currentChar = MARK maka EOP akan menyala (true) */
{
  pita = fopen(filename, "r");
  ADVFILE();
}

void ADVFILE()
/* Pita dimajukan satu karakter.
   I.S. : Karakter pada jendela = currentChar, currentChar != MARK
   F.S. : currentChar adalah karakter berikutnya dari currentChar yang lama,
          currentChar mungkin = MARK
          Jika  currentChar = MARK maka EOP akan menyala (true) */
{
  retval = fscanf(pita, "%c", &currentChar);
  EOP = (retval < 0);
  if (EOP)
  {
    fclose(pita);
  }
}

void IgnoreNewLine()
{
  while (currentChar == MARK)
  {
    ADVFILE();
  }
}

void ADVWORDFILE()
{
  IgnoreNewLine();
  if (retval < 0)
  {
    EndWord = true;
  }
  else
  {
    CopyWordFile();
  }
}

void CopyWordFile()
{
  currentWord.Length = 0;
  while ((currentChar != MARK) && (currentWord.Length < NMax) && (!EOP))
  {
    currentWord.TabWord[currentWord.Length] = currentChar;
    currentWord.Length++;
    ADVFILE();
  }
}