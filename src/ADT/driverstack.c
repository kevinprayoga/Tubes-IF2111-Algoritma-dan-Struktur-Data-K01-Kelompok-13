#include <stdio.h>
#include "stack.h"

int main()
{
  Stack s;
  CreateEmptyStack(&s);
  if (IsEmptyStack(s))
  {
    printf("Stack kosong\n");
  }
  else if(!IsEmptyStack(s) && !IsFullStack(s))
  {
    printf("Stack tidak kosong dan tidak penuh\n");
  }
  else if (IsFullStack(s))
  {
    printf("Stack penuh\n");
  }

  info str = "test";
  Push(&s, str);
  info str1 = "haha";
  Push(&s, str1);

  int command = countStack(s);
  printStack(&s, command);

  Pop(&s, &str1);
  Pop(&s, &str);

  return 0;
}