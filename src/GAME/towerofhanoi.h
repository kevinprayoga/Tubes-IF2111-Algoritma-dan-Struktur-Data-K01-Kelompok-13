#ifndef TOH_
#define TOH_

#include "../ADT/stackTOH.h"
#include "../console.h"
#include "../ADT/mesinkata.h"
#include "../boolean.h"

char* intToHanoi(int n);

char* intToAlas(int n);

void printAlas(int n, int length);

void display(Tower A, Tower B, Tower C, int n);

void printToMiddle(char* str, int length);

char wordToChar(Word K);

boolean isValid(Word K);

boolean isWordNumber(Word K);

int toh();

int scoring(int n, int move);

#endif