#include <stdio.h>
#include "boolean.h"

#ifndef CMD_LAIN_
#define CMD_LAIN_

boolean isCommand();
/*
Mengembalikan true apabila command dikenali
*/

void commandLain();
/*
Jika command tidak dikenali, maka program meminta input command baru
*/

#endif