#include "snake.h"

void generateMeteor(point *meteor, point *obstacle1, point *obstacle2, point *food, point *crater, List snake, boolean *dead)
{
    // KAMUS
    boolean drop = false;
    address p = First(snake);
    point head;

    // ALGORITMA
    srand(time(NULL));
    CreatePoint(meteor, rand() % 5, rand() % 5);
    do {
        if (!isPointEq(*meteor, *obstacle1) && !isPointEq(*meteor, *obstacle2) && !isPointEq(*food, *meteor) && !isPointEq(*meteor, *crater)) {
            drop = true;
            break;
        } else {
            srand(rand());
            CreatePoint(meteor, rand() % 5, rand() % 5);
        }
    } while (!drop);
    CreatePoint(&head, InfoX(First(snake)), InfoY(First(snake)));
    if (isPointEq(*meteor, head))
    {
        *dead = true;
    }
}

void generateFood(point meteor, point obstacle1, point obstacle2, point *food, point crater, List snake)
{
    // KAMUS
    boolean drop = false;

    // ALGORITMA
    srand(time(NULL));
    do {
        srand(rand());
        CreatePoint(food, rand() % 5, rand() % 5);
        printf("food:");
        displayPoint(*food);
        printf("\n");
        if (isPointEq(*food, obstacle1)) printf("A\n");
        else printf("B\n");
        printf("Obs1 %d\n", isPointEq(*food, obstacle1));
        printf("Obs2 %d\n", isPointEq(*food, obstacle2));
        printf("Crater %d\n", isPointEq(*food, crater));
        printf("Meteor %d\n", isPointEq(*food, meteor));
        printf("head %d\n", isPointEq(*food, Info(First(snake))));
        address P = First(snake);
        while (P != Nil) {
            displayPoint(Info(P));
            P = Next(P);
        }
        printf("Lagi nyari snek\n");
        Search(snake, *food);
        printf("Berhasil search\n");
    } while (isPointEq(*food, obstacle1) || isPointEq(*food, obstacle2) || isPointEq(*food, meteor) || isPointEq(*food, crater) || (Search(snake, *food) != NULL));
}

point generateObstacle(point obstacle)
{
    // KAMUS
    point obs2;
    boolean drop = false;
    
    // ALGORITMA
    srand(time(NULL));
    CreatePoint(&obs2, rand() % 5, rand() % 5);
    while (!drop)
    {
        if (!isPointEq(obstacle, obs2)) {
            drop = true;
            break;
        } else {
            CreatePoint(&obs2, rand() % 5, rand() % 5);
        }
    }
    return obs2;
}

void generateHead(point *obstacle1, point *obstacle2, List *snake)
{
    // KAMUS
    boolean drop = false;
    point head;

    // ALGORITMA
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
    InsVFirst(snake, head);
}

void growSnake(List *snake, point *obstacle1, point *obstacle2, point *crater, point *meteor, boolean *dead, int *score)
{
    // KAMUS
    point grow;
    address adrTail = First(*snake);
    boolean add = true;

    // ALGORITMA
    // cari tail
    while (Next(adrTail) != Nil) {
        adrTail = Next(adrTail);
    }

    CreatePoint(&grow, InfoX(adrTail) - 1, InfoY(adrTail)); // bikin di sebelah kiri dari tail
    if (isPointEq(grow, *obstacle1) || isPointEq(grow, *obstacle2) || isPointEq(grow, *crater) || isPointEq(grow, *meteor) || (Search(*snake, grow) != Nil)) {
        CreatePoint(&grow, InfoX(adrTail), InfoY(adrTail) - 1); // atas
        if (isPointEq(grow, *obstacle1) || isPointEq(grow, *obstacle2) || isPointEq(grow, *crater) || isPointEq(grow, *meteor) || (Search(*snake, grow) != Nil)) {
            CreatePoint(&grow, InfoX(adrTail), InfoY(adrTail) + 1); // bawah
            if (isPointEq(grow, *obstacle1) || isPointEq(grow, *obstacle2) || isPointEq(grow, *crater) || isPointEq(grow, *meteor) || (Search(*snake, grow) != Nil)) {
                CreatePoint(&grow, InfoX(adrTail) + 1, InfoY(adrTail)); // kanan
                if (isPointEq(grow, *obstacle1) || isPointEq(grow, *obstacle2) || isPointEq(grow, *crater) || isPointEq(grow, *meteor) || (Search(*snake, grow) != Nil)) {
                    *dead = true;
                    add = false;
                }
            }    
        }
    }
    if (add) {
        teleport(&grow); // supaya tembus dinding field
        InsVLast(snake, grow);
    }
    *score = (NbElmt(*snake) * 2);
}

boolean isValidInput(char *cmd, List snake, point *crater)
{
    // KAMUS
    point loc;

    // ALGORITMA
            printf("%s\n", cmd);

    if (strcompare("w", cmd) || strcompare("W", cmd)) {
        CreatePoint(&loc, InfoX(First(snake)), InfoY(First(snake))-1);
        displayPoint(loc);
        teleport(&loc);
        displayPoint(loc);
        address search = Search(snake, loc);
        // jika w menyebabkan head menabrak crater atau dirinya sendiri, program harus minta input ulang
        if (isPointEq(loc, *crater)) {
            printf("Meteor masih panas, Anda belum dapat kembali ke titik tersebut.\nSilakan masukkan command lainnya.\n");
            return false;
        } else if (search != Nil) {
            printf("Anda tidak dapat bergerak ke tubuh Anda sendiri!\nSilakan masukkan command yang lain.\n");
            return false;
        } else {
            return true;
        }
    } else if (strcompare("a", cmd) || strcompare("A", cmd)) {
        CreatePoint(&loc, InfoX(First(snake))-1, InfoY(First(snake)));
        displayPoint(loc);
        teleport(&loc);
        displayPoint(loc);
        address search = Search(snake, loc);
        // jika a menyebabkan head menabrak crater atau dirinya sendiri, program harus minta input ulang
        if (isPointEq(loc, *crater)) {
            printf("Meteor masih panas, Anda belum dapat kembali ke titik tersebut.\nSilakan masukkan command lainnya.\n");
            return false;
        } else if (search != Nil) {
            printf("Anda tidak dapat bergerak ke tubuh Anda sendiri!\nSilakan masukkan command yang lain.\n");
            return false;
        } else {
            return true;
        }
    } else if (strcompare("s", cmd) || strcompare("S", cmd)) {
        CreatePoint(&loc, InfoX(First(snake)), InfoY(First(snake))+1);
        displayPoint(loc);
        teleport(&loc);
        displayPoint(loc);
        address search = Search(snake, loc);
        // jika s menyebabkan head menabrak crater atau dirinya sendiri, program harus minta input ulang
        if (isPointEq(loc, *crater)) {
            printf("Meteor masih panas, Anda belum dapat kembali ke titik tersebut.\nSilakan masukkan command lainnya.\n");
            return false;
        } else if (search != Nil) {
            printf("Anda tidak dapat bergerak ke tubuh Anda sendiri!\nSilakan masukkan command yang lain.\n");
            return false;
        } else {
            return true;
        }
    } else if (strcompare("d", cmd) || strcompare("D", cmd)) {
        CreatePoint(&loc, InfoX(First(snake))+1, InfoY(First(snake)));
        displayPoint(loc);
        teleport(&loc);
        displayPoint(loc);
        address search = Search(snake, loc);
        // jika d menyebabkan head menabrak crater atau dirinya sendiri, program harus minta input ulang
        if (isPointEq(loc, *crater)) {
            printf("Meteor masih panas, Anda belum dapat kembali ke titik tersebut.\nSilakan masukkan command lainnya.\n");
            return false;
        } else if (search != Nil) {
            printf("Anda tidak dapat bergerak ke tubuh Anda sendiri!\nSilakan masukkan command yang lain.\n");
            return false;
        } else {
            return true;
        }
    } else {
        // selain WASD/wasd input tidak valid
        printf("Input tidak valid!\nSilakan masukkan command yang lain\n");
        return false;
    }
}

void moveSnake(char *cmd, List *snake)
{
    // KAMUS
    point move, dump;
    
    // ALGORITMA
    if (strcompare("w", cmd) || strcompare("W", cmd)) {
        CreatePoint(&move, InfoX(First(*snake)), InfoY(First(*snake))-1);
    } else if (strcompare("s", cmd) || strcompare("S", cmd)) {
        CreatePoint(&move, InfoX(First(*snake)), InfoY(First(*snake))+1);
    } else if (strcompare("a", cmd) || strcompare("A", cmd)) {
        CreatePoint(&move, InfoX(First(*snake))-1, InfoY(First(*snake)));
    } else if (strcompare("d", cmd) || strcompare("D", cmd)) {
        CreatePoint(&move, InfoX(First(*snake))+1, InfoY(First(*snake)));
    }
    teleport(&move);
    InsVFirst(snake, move);
    DelVLast(snake, &dump);
}

void teleport(point *pt)
{
    ABSIS(*pt) = (ABSIS(*pt) + 5) % 5;
    ORDINAT(*pt) = (ORDINAT(*pt) + 5) % 5;
}

char *inputCmd()
{
   printf("Silakan masukkan command Anda: ");
   return readQ();
}

boolean isCollideMeteor(List snake, point meteor)
{
    return (Search(snake, meteor) != Nil); // kalau != Nil berarti ketemu, artinya nabrak
}

void collideMeteor(List snake, point *meteor, boolean *dead, int *score)
{
    if (isPointEq(*meteor, Info(First(snake)))) {
        *dead = true;
        printf("Kepala snek terkena meteor!:(\n");
    } else {
        printf("Snek nabrak meteor!:(\n");
    }
    DelP(&snake, *meteor);
    *score = NbElmt(snake) *2;
}

boolean isCollideObstacle(List snake, point obstacle1, point obstacle2)
{
    return((Search(snake, obstacle1) != Nil) || (Search(snake, obstacle2) != Nil));
}

void collideObstacle(List snake, point *obstacle1, point *obstacle2, boolean *dead, int *score)
{
    printf("Mati nabrak obstacle:(\n");
    *dead = true;
    *score = NbElmt(snake) * 2;
}

void displayField(List snake, point meteor, point food, point crater, point obstacle1, point obstacle2)
{
    // KAMUS
    point loc;
    int i, j;

    // ALGORITMA
    printf("+-----+\n");
    for (i = 0; i < 5; i++)
    {
        printf("|");
        for (j = 0; j < 5; j++)
        {
            // ini ceritanya bikin point dari setiap titik pada field
            // kalau pointnya merupakan head, dia print H, dst...
            CreatePoint(&loc, j, i);
            if (isPointEq(loc, Info(First(snake)))) {
                printf("H");
            } else if (isPointEq(loc, food)) {
                printf("O");
            } else if (isPointEq(loc, meteor)) {
                printf("M");
            } else if (isPointEq(loc, obstacle1) || isPointEq(loc, obstacle2)) {
                printf("#");
            } else if (Search(snake, loc) != Nil) {
                printf("X"); 
            } else {
                printf(" ");
            }
        }
        printf("|");
        printf("\n");
    }
    printf("+-----+\n");
}

int main()
{
    // KAMUS
    List snake;
    point meteor, crater, obstacle1, obstacle2, food;
    boolean dead = false;
    int turn, len, score;
    char *moveCmd;

    // ALGORITMA
    // generate field awal: snek, obstacle, makanan
    printf("Selamat datang di Snek on Meteor!\n");
    printf("Mengenerate peta, snek, obstacle, dan makanan...\n");
    printf("Berhasil di-generate!\n");
    CreatePointNil(&meteor);
    displayPoint(meteor);
    printf("meteor berhasil di generate\n");
    CreatePointNil(&crater);
    displayPoint(crater);
    printf("crater berhasil di generate\n");
    srand(time(0));
    CreatePoint(&obstacle1, rand() % 5, rand() % 5);
    displayPoint(obstacle1);
    printf("obstacle1 berhasil di generate\n");
    obstacle2 = generateObstacle(obstacle1);
    displayPoint(obstacle2);
    printf("obstacle2 berhasil di generate\n");
    CreateEmpty(&snake);
    generateHead(&obstacle1, &obstacle2, &snake);
    address P = First(snake);
    while (P != Nil) {
        displayPoint(Info(P));
        P = Next(P);
    }
    printf("head berhasil di generate\n");
    score = NbElmt(snake) * 2;
    printf("score: %d\n", score);
    growSnake(&snake, &obstacle1, &obstacle2, &crater, &meteor, &dead, &score);
    P = First(snake);
    while (P != Nil) {
        displayPoint(Info(P));
        P = Next(P);
    }
    printf("ekor berhasil di generate\n");
    printf("score: %d\n", score);
    growSnake(&snake, &obstacle1, &obstacle2, &crater, &meteor, &dead, &score);
    P = First(snake);
    while (P != Nil) {
        displayPoint(Info(P));
        P = Next(P);
    }
    printf("ekor2 berhasil di generate\n");
    printf("score: %d\n", score);
    CreatePointNil(&food);
    generateFood(meteor, obstacle1, obstacle2, &food, crater, snake);
    printf("food berhasil di generate\ndisplay:\n");

    while (!dead)
    {
        displayField(snake, meteor, food, crater, obstacle1, obstacle2);
        generateMeteor(&meteor, &obstacle1, &food, &obstacle2, &crater, snake, &dead);
        // input command
        moveCmd = inputCmd();
        printf("%s\n", moveCmd);

        if (isValidInput(moveCmd, snake, &meteor)) {
            moveSnake(moveCmd, &snake);
            address P = First(snake);
            while (P != Nil) {
                displayPoint(Info(P));
                P = Next(P);
            }
            if (isCollideMeteor(snake, meteor)) {
                collideMeteor(snake, &meteor, &dead, &score);
                displayField(snake, meteor, food, crater, obstacle1, obstacle2);
            }
            if (isCollideObstacle(snake, obstacle1, obstacle2)) {
                collideObstacle(snake, &obstacle1, &obstacle2, &dead, &score);
                displayField(snake, meteor, food, crater, obstacle1, obstacle2);
            }
            if (isPointEq(Info(First(snake)), food)) {
                growSnake(&snake, &obstacle1, &obstacle2, &crater, &meteor, &dead, &score);
                generateFood(meteor, obstacle1, obstacle2, &food, crater, snake);
                displayField(snake, meteor, food, crater, obstacle1, obstacle2);
            }
        } else {
            printf("Mentok cuy\n");
        }
    }

    score = NbElmt(snake) * 2;

    // cek apakah mati
    if (dead) {
        printf("Game over! Score Anda: %d\n", score);
    } 

    return score;
}