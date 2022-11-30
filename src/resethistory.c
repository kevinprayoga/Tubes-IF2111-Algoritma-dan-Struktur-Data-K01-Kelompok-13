#include "resethistory.h"
#include <stdio.h>
#include "function.h"

void resetHistory(Stack *s)
{
  printf("\nAPAKAH KAMU YAKIN INGIN MELAKUKAN RESET HISTORY (YA/TIDAK)? ");
  char *command;
  command = readQ();
  if (strcompare(command, "YA") || strcompare(command, "ya"))
  {
    while (!IsEmptyStack(*s))
    {
      info val;
      Pop(s, &val);
    }
    printf("\nHistory berhasil di-reset.\n");
  }
  else if (strcompare(command, "TIDAK") || strcompare(command, "tidak"))
  {
    printf("\nHistory tidak jadi di-reset. Berikut adalah daftar Game yang telah dimainkan\n");
    int num = countStack(*s);
    printStack(s, num);
  }
  else
  {
    printf("Command tidak dikenali, silakan masukan command yang valid.\n");
    resetHistory(s);
  }
}