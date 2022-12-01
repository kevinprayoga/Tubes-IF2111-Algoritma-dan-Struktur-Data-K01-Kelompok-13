#ifndef MESIN_DUNGEON
#define MESIN_DUNGEON

#include "../boolean.h"

#define end 'n'

/* State Mesin */
extern char curr;
extern boolean terminate;

void startArt(char* name);
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : sembarang
   F.S. : curr adalah karakter pertama pada pita
          Jika curr != end maka terminate akan padam (false)
          Jika curr = end maka terminate akan menyala (true) */

void advArt();
/* Pita dimajukan satu karakter.
   I.S. : Karakter pada jendela = curr, curr != end
   F.S. : curr adalah karakter berikutnya dari curr yang lama,
          curr mungkin = end
          Jika curr = end maka terminate akan menyala (true) */

void printArt(char* name);
/* Menampilkan karakter terkini.
   I.S. : Karakter pada jendela = curr, curr != end
   F.S. : curr adalah karakter berikutnya dari curr yang lama,
          curr mungkin = end
          Jika curr = end maka terminate akan menyala (true) */

#endif