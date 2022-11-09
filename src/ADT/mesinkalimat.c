#include <stdio.h>
#include "mesinkalimat.h"

/* State Mesin Kata */
boolean EndSentence;
Sentence currentSentence;

void IgnoreBlanksKalimat()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */
{
  while (currentChar == BLANK2)
    ADV();
}

void STARTSENTENCE()
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */
{
  START();
  IgnoreBlanksKalimat();
  if (currentChar == MARK)
  {
    EndSentence = true;
  }
  else
  {
    EndSentence = false;
    CopySentence();
  }
}

void ADVSENTENCE()
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */
{
  IgnoreBlanksKalimat();
  CopySentence();
  if (currentChar == MARK)
  {
    EndSentence = true;
  }
}

void CopySentence()
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
{
  currentSentence.Length = 0;
  while ((currentChar != MARK) && (currentChar != BLANK2) && (currentSentence.Length < NMax))
  {
    currentSentence.TabSentence[currentSentence.Length] = currentChar;
    currentSentence.Length++;
    ADV();
  }
}