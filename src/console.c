#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "console.h"

void start(ArrayDin *arr)
{
  FILE *file;
  char command = *readQ();
  if (command == "START")
  {
    file = fopen("config.txt", "r");
    MakeArrayDin();
    STARTWORD();
    int num = atoi(currentWord.TabWord);
    for (int i = 0; i < num; i++)
    {
      ADVWORD();
      InsertAt(arr, currentWord.TabWord, i);
    }
    printf("File konfigurasi sistem berhasil dibaca. BNMO berhasil dijalankan.");
  }
}

void load(ArrayDin *arr, char filename)
{
  FILE *file;
  int i;
  char command = *readQ();
  if (command == "LOAD")
  {
    ADVWORD();
    if (currentWord.TabWord[currentWord.Length - 1] != 't' && currentWord.TabWord[currentWord.Length - 2] != 'x' && currentWord.TabWord[currentWord.Length - 3] != 't' && currentWord.TabWord[currentWord.Length - 4] != '.')
    {
      printf("File konfigurasi sistem tidak ditemukan.");
    }
    else
    {
      filename = wordToString(currentWord);
      file = fopen(filename, "r");
      MakeArrayDin();
      STARTWORD();
      int num = atoi(currentWord.TabWord);
      for (i = 0; i < num; i++)
      {
        ADVWORD();
        InsertAt(arr, currentWord.TabWord, i);
      }
      printf("File konfigurasi sistem berhasil dibaca. BNMO berhasil dijalankan.");
    }
  }
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

void deleteGame(ArrayDin *arr, Queue q)
{
  int num;
  ElType val;
  char command, command2;
  command = *readQ();
  if (command == "DELETE")
  {
    ADVWORD();
    command2 = wordToString(currentWord);
    if (command2 == "GAME")
    {
      printf("Berikut adalah daftar game yang tersedia\n");
      for (int i = 0; i < arr->Neff; i++)
      {
        printf("%d. %s\n", i + 1, arr->A[i]);
      }
      scanf("Masukkan nomor game yang akan dihapus: %d\n", &num);
      val = arr->A[num - 1];
      if (num - 1 > 4 && num - 1 < Length(*arr) && (!isMemberQ(q, val)))
      {
        DeleteAt(arr, num - 1);
        printf("\nGame berhasil dihapus");
      }
      else
      {
        printf("\nGame gagal dihapus");
      }
    }
  }
}

boolean isMemberQ(Queue q, ElType val)
{
  int i = 0;
  boolean found = false;
  while (i < length(q) && (!found))
  {
    if (q.buffer[i] == val)
    {
      found = true;
    }
  }
  return found;
}

void playGame(Queue *q, ArrayDin arrReady)
{
  char command, command2;
  command = *readQ();
  if (command == "PLAY")
  {
    ADVWORD();
    command2 = wordToString(currentWord);
    if (command2 == "GAME")
    {
      int i = 0;
      boolean found = false;
      while (i < Length(arrReady) && (!found))
      {
        if (arrReady.A[i] == HEAD(*q))
        {
          found = true;
        }
        else
        {
          i++;
        }
      }
      ElType val;
      if (found)
      {
        printf("Loading %s ...", HEAD(*q));
        dequeue(q, &val);
      }
      else
      {
        printf("Game %s masih dalam maintenance, belum dapat dimainkan.\nSilahkan pilih game lain.", HEAD(*q));
        dequeue(q, &val);
      }
    }
  }
}