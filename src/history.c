#include <stdio.h>
#include <stdlib.h>
#include "history.h"

void history(Stack *s, int command)
{
  printf("\nBerikut adalah daftar game yang telah dimainkan\n");
  if (IsEmptyStack(*s))
  {
    printf("\nTidak ada daftar game yang telah dimainkan\n");
  }
  else
  {
    printStack(s, command);
  }
}