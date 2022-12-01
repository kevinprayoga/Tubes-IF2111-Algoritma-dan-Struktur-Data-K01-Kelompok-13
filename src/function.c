#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "function.h"

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
  // char *str = (char *)malloc(sizeof(char) * (word.Length));
  char *str = (char *)malloc(sizeof(char) * (word.Length + 1));
  int i;
  for (i = 0; i < word.Length; i++)
  {
    str[i] = word.TabWord[i];
  }
  str[word.Length] = '\0';
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

char *firststring(char *command)
{
  int i = 0;
  char *firststr;
  firststr = (char *)malloc(50 * sizeof(char));
  while (command[i] != BLANK && command[i] != '\0')
  {
    *(firststr + i) = command[i];
    i++;
  }
  firststr[i] = '\0';
  return firststr;
}

char *secondstring(char *command)
{
  int i = 0;
  int j = 0;
  char *secstr;
  secstr = (char *)malloc(50 * sizeof(char));
  while (command[i] != BLANK && command[i] != '\0')
  {
    i++;
  }
  while (command[i] == BLANK)
  {
    i++;
  }

  while (command[i] != BLANK && command[i] != '\0')
  {
    secstr[j] = command[i];
    i++;
    j++;
  }
  secstr[j] = '\0';
  return secstr;
}

char *thirdstring(char *command)
{
  int i = 0;
  int j = 0;
  char *thirdstr;
  thirdstr = (char *)malloc(50 * sizeof(char));
  while (command[i] != BLANK && command[i] != '\0')
  {
    i++;
  }
  while (command[i] == BLANK)
  {
    i++;
  }
  while (command[i] != BLANK && command[i] != '\0')
  {
    i++;
  }
  while (command[i] == BLANK)
  {
    i++;
  }
  while (command[i] != '\0')
  {
    thirdstr[j] = command[i];
    i++;
    j++;
  }
  thirdstr[j] = '\0';
  return thirdstr;
}

int space_char(char *str)
{
    int count = 0;
    while(*str != '\0')
    {
        if(*str == ' ')
        {
            count++;
        }
        str++;
    }
    return count;
}

char *strconcat(char *dest, char *src){
    char *ret;
    ret = (char *) malloc((stringLength(dest) + stringLength(src) + 1) * sizeof(char));
    int i = 0;
    while (dest[i] != '\0')
    {
        ret[i] = dest[i];
        i++;
    }
    int j = 0;
    ret[i] = ' ';
    i++;
    while (src[j] != '\0')
    {
        ret[i] = src[j];
        i++;
        j++;
    }
    ret[i] = '\0';
    return ret;
}

boolean isMemberQ(Queue q, char* val){
    int i = 0;
    boolean found = false;
    while (i <= q.idxTail && !found){
        if (strcompare(val, q.buffer[i])){
            found = true;
        }
        i++;
    }
    return found;
}

int strToInt(char *str){
    int i = 0;
    int ans = 0;
    while (i < stringLength(str)){
        ans = ans * 10 + (str[i] - '0');
        i++;
    }
    return ans;
}

boolean isNum(char *str){
    int i = 0;
    boolean found = true;
    while (i < stringLength(str) && found){
        if (str[i] < '0' || str[i] > '9'){
            found = false;
        }
        i++;
    }
    return found;
}