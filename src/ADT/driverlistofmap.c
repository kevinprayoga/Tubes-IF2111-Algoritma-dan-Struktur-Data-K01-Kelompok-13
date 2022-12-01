#include "listofmap.h"
#include <stdio.h>

int main()
{
  ListMap L;
  CreateEmptyListMap(&L);
  CreateEmptyMap(&L);

  InsertMap(&L, "a", 1, 1);
  InsertMap(&L, "b", 3, 1);
  InsertMap(&L, "c", 2, 1);
  InsertMap(&L, "d", 3, 1);
  InsertMap(&L, "e", 0, 1);

  for (int i = 0; i < L.list[0].Count; i++)
  {
    printf("\n%s %d\n", L.list[0].Elements[i].Key, L.list[0].Elements[i].Value);
  }

  DeleteMap(&L, 1);

  return 0;
}