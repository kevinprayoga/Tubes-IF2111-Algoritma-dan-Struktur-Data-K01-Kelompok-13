#include "resethistory.h"
#include <stdio.h>
#include "function.h"

void resetHistory(Stack *s)
{
  printf("\nAPAKAH KAMU YAKIN INGIN MELAKUKAN RESET HISTORY? ");
  char *command;
  command = readQ();
  if (strcompare(command, "YA"))
  {
    while (!IsEmptyStack(*s))
    {
      info val;
      Pop(s, &val);
    }
    printf("\nHistory berhasil di-reset.\n");
  }
  else if (strcompare(command, "TIDAK"))
  {
    printf("\nHistory tidak jadi di-reset. Berikut adalah daftar Game yang telah dimainkan\n");
    int num = countStack(*s);
    printStack(s, num);
  }
  else
  {
    printf("\nInput tidak valid. Silakan coba lagi.\n");
  }
}