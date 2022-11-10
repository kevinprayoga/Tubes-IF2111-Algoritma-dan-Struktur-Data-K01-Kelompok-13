#include <stdio.h>
#include "mesinfile.h"

static FILE *pita;
static int retval;

void STARTFILE(char *filename)
{
  pita = fopen(filename, "r");
  ADVFILE();
}

void ADVFILE()
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