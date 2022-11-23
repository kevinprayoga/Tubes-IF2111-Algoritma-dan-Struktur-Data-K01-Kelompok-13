#include <stdio.h>
#include "point.h"

int main () {
    /* KAMUS */
    point p, p1;
    float dx, dy;

    /* ALGORITMA*/
    /* Test Baca dan Tulis */
    printf("Masukkan nilai absis dan ordinat: ");
    readPoint(&p);
    printf("Titik yang dibaca ");
    displayPoint(p);

    /* Test isOrigin */
    if (isOrigin(p)) {
    printf(" adalah titik origin");
    }
    printf("\n");
    
    /* Test geser */
    printf("Geser sejajar sumbu x sebesar = ");
    scanf("%f", &dx);
    printf("Geser sejajar sumbu y sebesar = ");
    scanf("%f", &dy);
    printf("Setelah digeser = ");
    displayPoint(move(p,dx,dy));
    printf("\n");

    return 0;
}