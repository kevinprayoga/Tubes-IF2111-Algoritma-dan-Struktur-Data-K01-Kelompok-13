#include <stdio.h>
#include "mesinkatav2.h"

/* State Mesin Kata */
boolean EndWord;
Word currentWord;

void IgnoreBlanksV2()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */
{
  while (currentChar == BLANK)
    ADVV2();
}

void STARTWORDV2()
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */
{
  STARTV2();
  IgnoreBlanksV2();
  if (currentChar == MARK)
  {
    EndWord = true;
  }
  else
  {
    EndWord = false;
    CopyWordV2();
  }
}

void ADVWORDV2()
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */
{
  IgnoreBlanks();
  CopyWordV2();
  if (currentChar == MARK)
  {
    EndWord = true;
  }
}

void CopyWordV2()
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
{
  currentWord.Length = 0;
  while ((currentChar != MARK)  && (currentChar != BLANK ) && (currentWord.Length < NMax))
  {
    currentWord.TabWord[currentWord.Length] = currentChar;
    currentWord.Length++;
    ADVV2();
  }
}