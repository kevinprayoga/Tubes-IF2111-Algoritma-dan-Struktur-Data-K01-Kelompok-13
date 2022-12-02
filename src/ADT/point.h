#ifndef POINT_H
#define POINT_H

#include "../boolean.h"
/**** Definisi Abstract Data Type POINT ****/
typedef struct {
    int x; /* absis */
    int y; /* ordinat */
} point;

#define NilPoint -999

/**** Selektor point ****/
#define ABSIS(p) (p).x
#define ORDINAT(p) (p).y

/**** Konstruktor POINT ****/
void CreatePoint (point *p, int x, int y);
/* Membentuk sebuah point dari x dan y dengan x sebagai absis dan y sebagai ordinat */
void CreatePointNil (point *p);
/* Membuat sebuah point dari x dan y pada koordinat (Nil, Nil). Nil didefinisikan sebagai -999 */

/**** Predikat ****/
boolean isOrigin (point p);
/* Mengirimkan nilai benar jika p adalah titik origin yaitu titik <0,0> */
boolean isPointEq (point p, point q);
/* Mengirimkan nilai benar jika p dan q adalah titik yang sama */

/**** Prosedur - Interaksi dengan I/O device ****/
void displayPoint (point p);
/* Nilai p ditulis ke layar dg format "(X,Y)" */

#endif