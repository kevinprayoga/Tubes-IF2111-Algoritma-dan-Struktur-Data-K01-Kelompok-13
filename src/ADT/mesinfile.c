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

void ignoreBlank()
{
  while (currentChar == BLANK)
  {
    ADVFILE();
  }
}

void ADVWORDFILE()
{
  IgnoreNewLine();
  ignoreBlank();
  if (EOP)
  {
    EndWord = true;
  }
  else
  {
    CopyWordFile();
  }
}

void ADVWORDFILEWOBLANK()
{
  IgnoreNewLine();
  ignoreBlank();
  if (EOP)
  {
    EndWord = true;
  }
  else
  {
    CopyWordFileWOBlank();
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
  if (EOP)
  {
    EndWord = true;
  }
}

void CopyWordFileWOBlank()
{
  currentWord.Length = 0;
  while ((currentChar != MARK) && (currentWord.Length < NMax) && (!EOP) && (currentChar != BLANK))
  {
    currentWord.TabWord[currentWord.Length] = currentChar;
    currentWord.Length++;
    ADVFILE();
  }
}