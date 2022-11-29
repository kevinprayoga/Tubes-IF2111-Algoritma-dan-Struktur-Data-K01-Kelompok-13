#include "snake.h"

void generateMeteor(point *meteor, point *obstacle1, point *obstacle2, point *food, point *crater, List snake, boolean dead)
{
    // KAMUS
    boolean drop = false;
    address p = First(snake);
    point head;

    // ALGORITMA
    srand(time(0));
    CreatePoint(meteor, rand() % 5, rand() % 5);
    do {
        if (!isPointEq(*meteor, *obstacle1) && !isPointEq(*meteor, *obstacle2) && !isPointEq(*food, *meteor) && !isPointEq(*meteor, *crater)) {
            drop = true;
        } else {
            CreatePoint(meteor, rand() % 5, rand() % 5);
        }
    } while (!drop);
    CreatePoint(&head, InfoX(First(snake)), InfoY(First(snake)));
    if (isPointEq(*meteor, head))
    {
        dead = true;
    }
}

void generateFood(point *meteor, point *obstacle1, point *obstacle2, point *food, point *crater, List snake)
{
    // KAMUS
    boolean drop = false;
    address p = First(snake);
    point body;

    // ALGORITMA
    srand(time(0));
    CreatePoint(&body, InfoX(p), InfoY(p));
    CreatePoint(food, rand() % 5, rand() % 5);
    do {
        if (!isPointEq(*food, *obstacle1) && !isPointEq(*food, *obstacle2) && !isPointEq(*food, *meteor) && !isPointEq(*food, *crater)) {
            while (p != Nil)
            {
                if (!isPointEq(*food, body)) {
                    drop = true;
                } else {
                    p = Next(p);
                    CreatePoint(&body, InfoX(p), InfoY(p));
                }
            }
        } else {
            CreatePoint(food, rand() % 5, rand() % 5);
        }
    } while (!drop);
}

point generateObstacle(point obstacle)
{
    // KAMUS
    point obs2;
    point loc;
    boolean drop = false;
    
    // ALGORITMA
    srand(time(0));
    CreatePoint(&obs2, rand() % 5, rand() % 5);
    while (!drop)
    {
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                CreatePoint(&loc, j, i);
                if (!isPointEq(loc, obs2) && !isPointEq(obstacle, obs2)) {
                    drop = true;
                    break;
                } else {
                    CreatePoint(&obs2, rand() % 5, rand() % 5);
                }
            }
        }
    }
    return obs2;
}

void generateHead(point *obstacle1, point *obstacle2)
{
    // KAMUS
    boolean drop = false;
    point head;
    List snake;

    // ALGORITMA
    CreateEmpty(&snake);
    srand(time(0));
    while (!drop)
    {
        CreatePoint(&head, rand() % 5, rand() % 5);
        if (!isPointEq(head, *obstacle1) && !isPointEq(head, *obstacle2)) {
            drop = true;
        } else {
            CreatePoint(&head, rand() % 5, rand() % 5);
        }    
    }
}

void growSnake(List snake, point *obstacle1, point *obstacle2, point *crater, point *meteor, boolean dead, int *score)
{
    // KAMUS
    point grow;
    address adrTail = First(snake);

    // ALGORITMA
    // cari tail
    while (adrTail != Nil) {
        adrTail = Next(adrTail);
    }

    *score = (NbElmt(snake) + 1) * 2;
    CreatePoint(&grow, InfoX(adrTail) - 1, InfoY(adrTail)); // bikin di sebelah kiri dari tail
    if (isPointEq(grow, *obstacle1) || isPointEq(grow, *obstacle2) || isPointEq(grow, *crater) || isPointEq(grow, *meteor) || (Search(snake, grow) != Nil)) {
        CreatePoint(&grow, InfoX(adrTail), InfoY(adrTail) - 1); // atas
        if (isPointEq(grow, *obstacle1) || isPointEq(grow, *obstacle2) || isPointEq(grow, *crater) || isPointEq(grow, *meteor) || (Search(snake, grow) != Nil)) {
            CreatePoint(&grow, InfoX(adrTail), InfoY(adrTail) + 1); // bawah
            if (isPointEq(grow, *obstacle1) || isPointEq(grow, *obstacle2) || isPointEq(grow, *crater) || isPointEq(grow, *meteor) || (Search(snake, grow) != Nil)) {
                CreatePoint(&grow, InfoX(adrTail) + 1, InfoY(adrTail)); // kanan
                if (isPointEq(grow, *obstacle1) || isPointEq(grow, *obstacle2) || isPointEq(grow, *crater) || isPointEq(grow, *meteor) || (Search(snake, grow) != Nil)) {
                    *score = (NbElmt(snake) * 2);
                    dead = true;
                }
            }    
        }
    }

    teleport(&grow); // supaya tembus dinding field
}

boolean isValidInput(char *cmd, List snake, point *crater)
{
    // KAMUS
    point loc;

    // ALGORITMA
    if (strcompare("w", cmd) || strcompare("W", cmd)) {
        CreatePoint(&loc, InfoX(First(snake)), InfoY(First(snake)-1));
        teleport(&loc);
        // jika w menyebabkan head menabrak crater atau dirinya sendiri, program harus minta input ulang
        if (isPointEq(loc, *crater)) {
            printf("Meteor masih panas, Anda belum dapat kembali ke titik tersebut.\nSilakan masukkan command lainnya.\n");
            return false;
        } else if (isPointEq(loc, Info(Search(snake, loc)))) {
            printf("Anda tidak dapat bergerak ke tubuh Anda sendiri!\nSilakan masukkan command yang lain.\n");
            return false;
        } else {
            return true;
        }
    } else if (strcompare("a", cmd) || strcompare("A", cmd)) {
        CreatePoint(&loc, InfoX(First(snake))-1, InfoY(First(snake)));
        teleport(&loc);
        // jika a menyebabkan head menabrak crater atau dirinya sendiri, program harus minta input ulang
        if (isPointEq(loc, *crater)) {
            printf("Meteor masih panas, Anda belum dapat kembali ke titik tersebut.\nSilakan masukkan command lainnya.\n");
            return false;
        } else if (isPointEq(loc, Info(Search(snake, loc)))) {
            printf("Anda tidak dapat bergerak ke tubuh Anda sendiri!\nSilakan masukkan command yang lain.\n");
            return false;
        } else {
            return true;
        }
    } else if (strcompare("s", cmd) || strcompare("S", cmd)) {
        CreatePoint(&loc, InfoX(First(snake)), InfoY(First(snake)+1));
        teleport(&loc);
        // jika s menyebabkan head menabrak crater atau dirinya sendiri, program harus minta input ulang
        if (isPointEq(loc, *crater)) {
            printf("Meteor masih panas, Anda belum dapat kembali ke titik tersebut.\nSilakan masukkan command lainnya.\n");
            return false;
        } else if (isPointEq(loc, Info(Search(snake, loc)))) {
            printf("Anda tidak dapat bergerak ke tubuh Anda sendiri!\nSilakan masukkan command yang lain.\n");
            return false;
        } else {
            return true;
        }
    } else if (strcompare("d", cmd) || strcompare("D", cmd)) {
        CreatePoint(&loc, InfoX(First(snake))+1, InfoY(First(snake)));
        teleport(&loc);
        // jika d menyebabkan head menabrak crater atau dirinya sendiri, program harus minta input ulang
        if (isPointEq(loc, *crater)) {
            printf("Meteor masih panas, Anda belum dapat kembali ke titik tersebut.\nSilakan masukkan command lainnya.\n");
            return false;
        } else if (isPointEq(loc, Info(Search(snake, loc)))) {
            printf("Anda tidak dapat bergerak ke tubuh Anda sendiri!\nSilakan masukkan command yang lain.\n");
            return false;
        } else {
            return true;
        }
    } else {
        // selain WASD/wasd input tidak valid
        printf("Input tidak valid!\nSilakan masukkan command yang lain/\n");
        return false;
    }
}

void moveSnake(char *cmd, List snake)
{
    // KAMUS
    point move, dump;

    // ALGORITMA
    if (strcompare("w", cmd) || strcompare("W", cmd)) {
        CreatePoint(&move, InfoX(First(snake)), InfoY(First(snake))-1);
        InsVFirst(&snake, move);
        DelVLast(&snake, &dump);
    } else if (strcompare("s", cmd) || strcompare("S", cmd)) {
        CreatePoint(&move, InfoX(First(snake)), InfoY(First(snake))+1);
        InsVFirst(&snake, move);
        DelVLast(&snake, &dump);
    } else if (strcompare("a", cmd) || strcompare("A", cmd)) {
        CreatePoint(&move, InfoX(First(snake))-1, InfoY(First(snake)));
        InsVFirst(&snake, move);
        DelVLast(&snake, &dump);
    } else if (strcompare("d", cmd) || strcompare("D", cmd)) {
        CreatePoint(&move, InfoX(First(snake))+1, InfoY(First(snake)));
        InsVFirst(&snake, move);
        DelVLast(&snake, &dump);
    }
}

void teleport(point *pt)
{
    if (ABSIS(*pt) < 0 || ABSIS(*pt) > 4) {
        ABSIS(*pt) = (ABSIS(*pt) + 5) % 5;
    }

    if (ORDINAT(*pt) < 0 || ORDINAT(*pt) > 4) {
        ORDINAT(*pt) = (ORDINAT(*pt) + 5) % 5;
    }
}

void inputCmd()
{
   printf("Silakan masukkan command Anda: ");
   STARTWORD();    
}

boolean isCollideMeteor(List snake, point meteor)
{
    return (Search(snake, meteor) != Nil); // kalau != Nil berarti ketemu, artinya nabrak
}

void collideMeteor(List snake, point *meteor, boolean dead, int *score)
{
    if (isPointEq(*meteor, Info(First(snake)))) {
        dead = true; 
    }
    DelP(&snake, *meteor);
    *score = (NbElmt(snake)-1) * 2;
}

boolean isCollideObstacle(List snake, point obstacle1, point obstacle2)
{
    return((Search(snake, obstacle1) != Nil) && (Search(snake, obstacle2) != Nil));
}

void collideObstacle(List snake, point *obstacle1, point *obstacle2, boolean dead, int *score)
{
    dead = true;
    if (isPointEq(*obstacle1, Info(Search(snake, *obstacle1)))) {
        DelP(&snake, *obstacle1);
    } else {
        DelP(&snake, *obstacle2);
    }
    dead = true;
    *score = (NbElmt(snake)-1) * 2;
}

void displayField(List snake, point meteor, point food, point crater, point obstacle1, point obstacle2)
{
    // KAMUS
    point loc;
    int i, j;
    char field[5][5];

    // ALGORITMA
    printf("+-----+\n");
    for (i = 0; i < 5; i++)
    {
        printf("|");
        for (j = 0; j < 5; j++)
        {
            // ini ceritanya bikin point dari setiap titik pada field
            // kalau pointnya merupakan head, dia nyimpen H, dst...
            CreatePoint(&loc, j, i);
            if (isPointEq(loc, Info(First(snake)))) {
                field[i][j] = "H";
            } else if (isPointEq(loc, food)) {
                field[i][j] = "O";
            } else if (isPointEq(loc, meteor)) {
                field[i][j] = "M";
            } else if (isPointEq(loc, crater)) {
                field[i][j] = "C";
            } else if (isPointEq(loc, obstacle1) || isPointEq(loc, obstacle2)) {
                field[i][j] = "#";
            } else if (Search(snake, loc) != Nil) {
                field[i][j] = "X"; //nah ini ceritanya body snake, masih bingung cara supaya body snake bisa 1,2,3...
            } else {
                field[i][j] = ' ';
            }
        }
        printf("|");
        printf("\n");
    }
    printf("+-----+");
}

int snakeOnMeteor()
{
    // KAMUS
    List snake;
    point meteor, crater, obstacle1, obstacle2, food;
    boolean dead;
    int turn, len, score;

    // ALGORITMA
    // generate field awal: snek, obstacle, makanan
    printf("Selamat datang di Snek on Meteor!\n");
    printf("Mengenerate peta, snek, obstacle, dan makanan...\n");
    printf("Berhasil di-generate!\n");
    CreatePointNil(&meteor);
    CreatePointNil(&crater);
    srand(time(0));
    CreatePoint(&obstacle1, rand() % 5, rand() % 5);
    obstacle2 = generateObstacle(obstacle1);
    generateHead(&obstacle1, &obstacle2);
    score = NbElmt(snake) * 2;
    growSnake(snake, &obstacle1, &obstacle2, &crater, &meteor, false, &score);
    growSnake(snake, &obstacle1, &obstacle2, &crater, &meteor, false, &score);
    generateFood(&meteor, &obstacle1, &obstacle2, &food, &crater, snake);
    displayField(snake, meteor, food, crater, obstacle1, obstacle2);

    // main loop sampe mati, blm kepikiran gmn cara handle turnnya, krn tiap 1 turn
    // harus ngecek apakah nabrak meteor, obstacle, atau makanan
    // abis tu ngecek apakah nabrak diri sendiri
    // pokoknya kalau nabrak: meteor di kepala/obstacle = game over
    // nabrak crater/dirinya sendiri = input ulang
    // gak bisa tumbuh lagi = game over

}