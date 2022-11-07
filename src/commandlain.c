#include <stdio.h>
#include "commandlain.h"
#include "console.h"

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

// ide 1
boolean isCommand(char command)
{
    boolean found = false;
    command = *readQ();
    int i = 0;
    char validCmd[11][50] = {"START", "SAVE", "LOAD", "CREATE GAME", "LIST GAME", "DELETE GAME",
                            "QUEUE GAME", "PLAY GAME", "SKIPGAME", "QUIT", "HELP"};
    while ((!found) && (i < 11))
    {
        if (command == validCmd[i])
        {
            found = true;
        }
        else
        {
            i++;
        }
    }

    return found;
}

void commandLain()
{
    if(!isCommand())
    {
        printf("Command tidak dikenali, silakan masukan command yang valid.\n");
    }
}

//ide 2
boolean isWordSame(Word word1, Word word2)
{
  boolean diff = false;
  int i = 0;
  if (word1.Length == word2.Length)
  {
    while(!EndWord && !diff)
    {
      if (word1.TabWord[i] != word2.TabWord[i])
      {
        diff = true;
      }
      else
      {
        ADVWORD();
      }
    }
  }
  
  return diff;
}

void cmdLain()
{
  Word word1, word2;
  if(!isWordSame(word1,word2))
  {
    printf("Command tidak dikenali, silakan masukan command yang valid.\n");
  }
}