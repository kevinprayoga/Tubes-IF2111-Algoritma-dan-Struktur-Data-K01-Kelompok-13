#include <stdio.h>
#include "mesinkar.h"

/* State Mesin */
char currentChar;
boolean EOP;

static FILE *pita;
static int retval;

void START()
{
  pita = stdin;
  ADV();
}

void ADV()
{
  retval = fscanf(pita, "%c", &currentChar);
}