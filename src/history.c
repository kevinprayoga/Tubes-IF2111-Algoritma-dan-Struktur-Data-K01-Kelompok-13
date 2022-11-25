#include <stdio.h>
#include <stdlib.h>
#include "history.h"

void history(Stack *s, int command)
{
  if (IsEmptyStack(*s) || command < 1)
  {
    printf("\nTidak ada daftar game yang telah dimainkan\n");
  }
  else
  {
    printf("\nBerikut adalah daftar game yang telah dimainkan\n");
    printStack(s, command);
  }
}