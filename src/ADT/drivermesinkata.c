#include <stdio.h>
#include "mesinkata.h"

int main()
{
  STARTWORD();
  while (!IsEOP())
  {
    printf("%s\n", currentWord.TabWord);
    ADVWORD();
  }
  return 0;
}