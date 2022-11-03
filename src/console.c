#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "console.h"

void start(ArrayDin *arr)
{
  int num;
  FILE* file;
  *readQ();
  file = fopen("config.txt", "r");
  MakeArrayDin();
  STARTWORD();
  num = atoi(currentWord.TabWord);
  for (int i = 0; i < num; i++)
  {
    ADVWORD();
    InsertAt(arr, currentWord.TabWord, i);
  }
  printf("File konfigurasi sistem berhasil dibaca. BNMO berhasil dijalankan.");
}

char *readQ()
{
  STARTWORD();
  return wordToString(currentWord);
}

char wordToString(Word word)
{
  char *str = (char *)malloc(sizeof(char) * word.Length);
  for (int i = 0; i < word.Length; i++)
  {
    str[i] = word.TabWord[i];
  }
  return str;
}

int wordToInt(Word word)
{
  int num = 0;
  for (int i = 0; i < word.Length; i++)
  {
    num += (word.TabWord[i] - '0') * pow(10, word.Length - i - 1);
  }
  return num;
}

void deleteGame(ArrayDin *arr, ArrayDin arrFirst)
{
  int num;
  boolean found;
  found = false;
  scanf("Masukkan nomor game yang akan dihapus: %d\n", &num);
  if (num > 0 && num <= Length(*arr))
  {
    int i = 0;
    while (i < Length(arrFirst) && (!found))
    {
      if (Get(arrFirst, i) == Get(*arr, num - 1))
      {
        found = true;
      }
      else
      {
        i++;
      }
    }
  }

  if (found == true)
  {
    
  }
  DeleteAt(arr, num);
}

void playGame(Queue *q)
{
  //nge peprint daftar game yg di queue
}