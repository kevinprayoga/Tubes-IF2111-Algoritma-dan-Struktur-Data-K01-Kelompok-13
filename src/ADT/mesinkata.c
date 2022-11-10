#include <stdio.h>
#include "mesinkata.h"

/* State Mesin Kata */
boolean EndWord;
Word currentWord;

void STARTWORD()
{
  START();
  if (currentChar == MARK)
  {
    EndWord = true;
  }
  else
  {
    EndWord = false;
    CopyWord();
  }
}

void ADVWORD()
{
  if (currentChar == MARK)
  {
    EndWord = true;
  }
  else
  {
    CopyWord();
  }
}

void CopyWord()
{
  currentWord.Length = 0;
  while ((currentChar != MARK) && (currentWord.Length < NMax))
  {
    currentWord.TabWord[currentWord.Length] = currentChar;
    currentWord.Length++;
    ADV();
  }
}