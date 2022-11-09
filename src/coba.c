#include <stdio.h>
#include <stdlib.h>
#include "coba.h"

char *readQ()
{
  STARTWORD();
  return wordToString(currentWord);
}

boolean strcompare(char *str1, char *str2)
{
  int i = 0;
  boolean found = false;
  if (stringLength(str1) != stringLength(str2))
  {
    return found;
  }
  else
  {
    while (!found && i < stringLength(str1))
    {
      if (str1[i] != str2[i])
      {
        return found;
      }
      i++;
    }
    return !found;
  }
}

int stringLength(char *str)
{
  int i = 0;
  while (str[i] != '\0')
  {
    i++;
  }
  return i;
}

char *wordToString(Word word)
{
  char *str = (char *)malloc(sizeof(char) * word.Length);
  int i;
  for (i = 0; i < word.Length; i++)
  {
    str[i] = word.TabWord[i];
  }
  str[i] = '\0';
  return str;
}

char *sentenceToString(Sentence sentence)
{
  char *str = (char *)malloc(sizeof(char) * sentence.Length);
  int i;
  for (i = 0; i < sentence.Length; i++)
  {
    str[i] = sentence.TabSentence[i];
  }
  str[i] = '\0';
  return str;
}

int wordToInt(Word word)
{
  int i = 0;
  int ans = 0;
  while (i < word.Length)
  {
    ans = ans * 10 + (word.TabWord[i] - '0');
    i++;
  }
  return ans;
}

int sentenceToInt(Sentence sentence)
{
  int i = 0;
  int ans = 0;
  while (i < sentence.Length)
  {
    ans = ans * 10 + (sentence.TabSentence[i] - '0');
    i++;
  }
  return ans;
}