#include "gameRNG.h"

void rng() {
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
   printf("Skor akurasi anda adalah %d/100.\n", 100/i);
}

int wordToInt(Word kata)
{
    int i = 0;
    int ans = 0;
    while (i < kata.Length){
        ans = ans*10 + (kata.TabWord[i] - '0');
        i++;
    }
    return ans;
}