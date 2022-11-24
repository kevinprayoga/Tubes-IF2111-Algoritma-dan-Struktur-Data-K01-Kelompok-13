#include <stdio.h>
#include "point.h"

/**** Konstruktor POINT ****/
void CreatePoint (point *p, float x, float y) {
/* Membentuk sebuah point p dari x dan y dengan x sebagai absis dan y sebagai
ordinat */
    /* ALGORITMA */
    ABSIS(*p) = x;
    ORDINAT(*p) = y;
}

/**** Predikat ****/
boolean isOrigin (point p) {
/* Mengirimkan nilai benar jika p adalah titik origin yaitu titik <0,0> */
    /* ALGORITMA */
    return ((ABSIS(p) == 0) && (ORDINAT(p) == 0));
}

/**** Prosedur - Interaksi dengan I/O device, BACA/TULIS ****/
void readPoint (point *p) {
/* Membentuk p dari x dan y yang dibaca dari keyboard */
    /* KAMUS */
    float x, y;
    /* ALGORITMA */
    scanf("%f %f", &x, &y);
    scanf("%f", &y);
    CreatePoint(p, x, y);
}

void displayPoint (point p) {
/* Nilai p ditulis ke layar dg format "(X,Y)" */
    /* ALGORITMA */
    printf("(%.2f,%.2f)", ABSIS(p), ORDINAT(p));
}

/**** Fungsi/Operasi lain terhadap point ****/
point movePoint (point p, float dx, float dy) {
/* Menggeser point p sebesar dx arah sumbu x dan dy arah sumbu y */
    /* KAMUS */
    point pt;
    /* ALGORITMA */
    ABSIS(pt) = ABSIS(p) + dx;
    ORDINAT(pt) = ORDINAT(p) + dy;
    return (pt);
}