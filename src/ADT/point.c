#include <stdio.h>
#include "point.h"

/**** Konstruktor POINT ****/
void CreatePoint (point *p, int x, int y) {
/* Membentuk sebuah point p dari x dan y dengan x sebagai absis dan y sebagai
ordinat */
    /* ALGORITMA */
    ABSIS(*p) = x;
    ORDINAT(*p) = y;
}
void CreatePointNil (point *p) {
/* Membuat sebuah point dari x dan y pada koordinat (Nil, Nil). Nil didefinisikan sebagai -999 */
    /* ALGORITMA */
    ABSIS(*p) = NilPoint;
    ORDINAT(*p) = NilPoint;
}

/**** Predikat ****/
boolean isOrigin (point p) {
/* Mengirimkan nilai benar jika p adalah titik origin yaitu titik <0,0> */
    /* ALGORITMA */
    return ((ABSIS(p) == 0) && (ORDINAT(p) == 0));
}

boolean isPointEq (point p, point q) {
/* Mengirimkan nilai benar jika p dan q adalah titik yang sama */
    /* ALGORITMA */
    return ((ABSIS(p) == ABSIS(q)) && (ORDINAT(p) == ORDINAT(q)));
}

/**** Prosedur - Interaksi dengan I/O device ****/
void displayPoint (point p) {
/* Nilai p ditulis ke layar dg format "(X,Y)" */
    /* ALGORITMA */
    printf("(%d,%d)", ABSIS(p), ORDINAT(p));
}