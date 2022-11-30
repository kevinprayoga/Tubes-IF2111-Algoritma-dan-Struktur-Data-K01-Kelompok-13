#include "gameRNG.h"

int rng() {
    printf(".------..------..------.\n");
    printf("|R.--. ||N.--. ||G.--. |\n");
    printf("| :(): || :(): || :/\\: |\n");
    printf("| ()() || ()() || :\\/: |\n");
    printf("| '--'R|| '--'N|| '--'G|\n");
    printf("`------'`------'`------'\n");
    printf("Selamat datang di game RNG!\n");
    printf("\nRNG Telah dimulai. Uji keberuntungan Anda dengan menebak angka.\n");
    srand(time(0));
    int rng = rand()%50;
    int ans;
    int i = 1;
    printf("Tebakan : ");
    STARTWORD();
    ans = wordToInt(currentWord);
    while (ans != rng){
        i++;
        if (ans > rng){
            printf("Lebih kecil.\n");
        } else {
            printf("Lebih besar.\n");
        }
        printf("Tebakan : ");
        STARTWORD();
        ans = wordToInt(currentWord);
   }
   printf("Ya, Tebakan adalah %d\n", rng);
   printf("Skor: %d\n", 100/i);

   return 100/i;
}