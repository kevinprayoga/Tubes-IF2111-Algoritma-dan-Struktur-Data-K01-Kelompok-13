#include <stdio.h>
#include <stdlib.h>
#include "history.h"

void history(Stack *s, int command)
{
  if (IsEmptyStack(*s) || command < 1)
  {
    printf("\nTidak ada daftar game yang telah dimainkan.\n");
  }
  else
  {
    printf("\nBerikut adalah daftar game yang telah dimainkan\n");
    printStack(s, command);
  }
}

void deleteHistory(Stack *s, ArrayDin arr, IdxType idx)
{
  Stack s1;
  CreateEmptyStack(&s1);
  info temp;
  ElType val = Get(arr, idx);
  for (int i = 0; i < countStack(*s); i++)
  {
    Pop(s, &temp);
    if (s->T[i] != val)
    {
      Push(&s1, temp);
    }
  }
  for (int i = 0; i < countStack(s1); i++)
  {
    Pop(&s1, &temp);
    Push(s, temp);
  }
}