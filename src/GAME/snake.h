#ifndef SNAKE_H
#define SNAKE_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "../console.h"
#include "../boolean.h"
#include "../ADT/mesinkata.h"
#include "../ADT/point.h"
#include "../ADT/listlinier.h"

void generateMeteor(point *meteor, point *obstacle1, point *obstacle2, point *food, List snake, boolean *dead);
/* Membuat meteor secara acak di suatu titik pada field. Meteor tidak mungkin ada di titik yang sama dengan
   obstacle maupun meteor. Jika meteor jatuh pada tubuh snake, panjang snake berkurang 1. Jika meteor jatuh
   pada kepala snake, permainan berakhir.
*/

void generateFood(point meteor, point obstacle1, point obstacle2, point *food, List snake);
/* Membuat food secara acak di suatu titik pada field. Food tidak mungkin ada di
   titik yang sama dengan tubuh snake, meteor, obstacle.
   I.S. belum ada food pada field
   F.S. ada 1 food pada suatu titik di field
*/
point generateObstacle(point obstacle);
/* Membuat obstacle pada map pada titik acak yang belum ada obstacle-nya.
   I.S. Sudah ada 1 obstacle pada field.
   F.S. Ada obstacle pada titik tersebut. Ada 2 obstacle pada field.*/

void generateHead(point *obstacle1, point *obstacle2, List *snake);
/* Membuat list snake sebagai tubuh ular, ukuran tubuhnya 3 unit sudah termasuk kepala.
   Snake ditaruh acak pada field, di tempat yang tidak ada obstaclenya.
   I.S. Field memiliki 2 obstacle, 0 snake.
   F.S. Field memiliki 2 obstacle, 1 snake yang berukurang 3 unit. */

void growSnake(List *snake, point *obstacle1, point *obstacle2, point *meteor, boolean *dead);
/* Menumbuhkan ekor snake
   I.S. ekor belum tumbuh
   F.S. Jika bisa, ekor tumbuh. Jika tidak bisa, snake mati:( skor dihitung dari jumlah elemen awal */

boolean isValidInput(char *cmd, List snake, point *meteor);
/* Mengecek apakah input valid.
   Input dikatakan valid jika input merupakan "wasdWASD" dan tidak menabrak meteor atau tubuhnya sendiri
   Jika input tidak valid, minta input ulang.*/

void moveSnake(char *cmd, List *snake);
/* Menggerakkan snake sesuai dengan input user.
   Snake bergerak dengan cara menghapus titik tail (titik terakhir
   pada tubuhnya) lalu menambahkan titik baru dengan arah sesuai input user
   sebagai head.
   I.S. input pasti valid (pasti wasd/WASD, pasti tidak menabrak meteor panas/tubuhnya sendiri)
   F.S. snake pindah */

void teleport(point *pt);
/* Supaya snek bisa nembus fieldnya */

char *inputCmd();
/* Program minta input */

boolean isCollideMeteor(List snake, point meteor);
/* Jika head menabrak meteor atau meteor jatuh pada tubuh snek, fungsi akan return true */

void collideMeteor(List snake, point *meteor, boolean *dead);
/* I.S. Snake dipastikan menabrak meteor, baik pada head maupun body.
   F.S. Tubuh snake berkurang 1, jika menabrak pada kepala snake akan mati.
        Skor berkurang 2 ((NbElmt(snake)-1) * 2) */

boolean isCollideObstacle(List snake, point obstacle1, point obstacle2);
/* Jika snake menabrak obstacle, fungsi akan return true */

void collideObstacle(List snake, point *obstacle1, point *obstacle2, boolean *dead);
/* I.S. Snake dipastikan menabrak obstacle 
   F.S. Game over. Panjang tubuh snake berkurang 1 (yang nabrak akan hilang).
        Skor berkurang 2 ((NbElmt(snake)-1) * 2) */

boolean cantMove(List snake, point *obstacle1, point *obstacle2, point *meteor, boolean *dead);
/* Mengembalikan nilai true jika head tidak bisa pergi ke manapun :( */

void displayField(List snake, point meteor, point food, point obstacle1, point obstacle2);
/* Menampilkan map */

int snekOnMeteor();
/* Main gem snek on meteor!＞﹏＜ */

#endif