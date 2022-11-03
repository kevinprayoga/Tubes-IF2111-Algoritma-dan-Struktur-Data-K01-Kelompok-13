#include "gameRNG.h"

void rng() {
    srand(time(0));
    int rng = rand()%50;
    int ans;
    int i = 1;
    printf("Tebakan : ");
    scanf("%d", &ans);
    while (ans != rng){
        i++;
        if (ans > rng){
            printf("Lebih kecil.\n");
        } else {
            printf("Lebih besar.\n");
        }
        printf("Tebakan : ");
        scanf("%d", &ans);
   }
   printf("Ya, Tebakan adalah %d\n", rng);
   printf("Skor akurasi anda adalah %d/100.\n", 100/i);
}