#ifndef HANGMANSET__H
#define HANGMANSET__H

#include "../ADT/set.h"
#include "../ADT/mesinkar.h"
#include "../ADT/mesinkata.h"
#include "../ADT/arraydin.h"
#include "../ADT/mesinfile.h"
#include "asciihangman.h"

char convert(char c);

boolean isChar(char c);

void loadkata(SetStr *S);

void printSet(SetChar S);

void hangmanset(int* score);

void saveKata();

int hangman();

#endif