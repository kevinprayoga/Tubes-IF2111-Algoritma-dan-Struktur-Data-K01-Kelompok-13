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

boolean isCommand()
{
    boolean found = false;
    char command, command2;
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
}

void commandLain()
{
    if(!isCommand())
    {
        printf("Command tidak dikenali, silakan masukan command yang valid.\n");
    }
}
