#include "snake.h"

void generateMeteor(point *meteor, point *obstacle1, point *obstacle2, point *food, point *crater, List snake)
{
    // KAMUS
    boolean drop = false;
    boolean dead = false;
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

void growSnake(List snake, point *obstacle1, point *obstacle2, point *crater, point *meteor)
{
    // KAMUS
    point grow;
    address adrTail = First(snake);
    boolean dead = false;
    boolean done = false;

    // ALGORITMA
    // cari tail
    while (adrTail != Nil) {
        adrTail = Next(adrTail);
    }
    CreatePoint(&grow, InfoX(adrTail) - 1, InfoY(adrTail));

    // cari tempat 
    if (isPointEq(grow, *obstacle1) || isPointEq(grow, *obstacle2) || isPointEq(grow, *crater) || isPointEq(grow, *meteor) || (Search(snake, grow) != Nil)) {
        CreatePointNil(&grow);
        CreatePoint(&grow, InfoX(adrTail), InfoY(adrTail) - 1);
        done = true;
    }
    if (isPointEq(grow, *obstacle1) || isPointEq(grow, *obstacle2) || isPointEq(grow, *crater) || isPointEq(grow, *meteor) || (Search(snake, grow) != Nil)) {
        CreatePointNil(&grow);
        CreatePoint(&grow, InfoX(adrTail), InfoY(adrTail) + 1);
        done = true;
    }
    if (isPointEq(grow, *obstacle1) || isPointEq(grow, *obstacle2) || isPointEq(grow, *crater) || isPointEq(grow, *meteor) || (Search(snake, grow) != Nil)) {
        CreatePointNil(&grow);
        CreatePoint(&grow, InfoX(adrTail) + 1, InfoY(adrTail));
        done = true;
    }

    if (ABSIS(grow) < 0 || ABSIS(grow) > 4) {
        ABSIS(grow) = (ABSIS(grow) + 5) % 5;
    }
    
    if (ORDINAT(grow) < 0 || ORDINAT(grow) > 4) {
        ORDINAT(grow) = (ORDINAT(grow) + 5) % 5;
    }

    if (!done) {
        dead = true;
    } else {
        InsVLast(&snake, grow);
    }
}

boolean isInputValid(char *cmd, List snake, point *meteor, point *crater, point *food, point *obstacle1, point *obstacle2)
{
    // KAMUS
    
    // ALGORITMA
    if (strcompare("w", cmd) || strcompare("W", cmd) ||
        strcompare("a", cmd) || strcompare("A", cmd) ||
        strcompare("s", cmd) || strcompare("S", cmd) ||
        strcompare("d", cmd) || strcompare("D", cmd)) {
            moveSnake(cmd, snake, &meteor, &crater, &food, &obstacle1, &obstacle2);
            return true;
    } else {
        invalidMove();
        return false;
    }
}



void moveSnake(char *cmd, List snake, point *meteor, point *crater, point *food, point *obstacle1, point *obstacle2)
{
    // KAMUS
    point move, dump;

    // ALGORITMA
    if (!isCollide() || ) {
        if (strcompare("w", cmd) || strcompare("W", cmd)) {
            CreatePoint(&move, InfoX(First(snake)), InfoY(First(snake)-1));
            InsVFirst(&snake, move);
            DelVLast(&snake, &dump);
        } else if (strcompare("s", cmd) || strcompare("S", cmd)) {
            CreatePoint(&move, InfoX(First(snake)), InfoY(First(snake)+1));
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
}

boolean isCollide(char *cmd, List snake, point *meteor, point *crater, point *food, point *obstacle1, point *obstacle2)
{

}

void invalidMove()
{
   printf("Silakan masukkan command Anda: ");
   STARTWORD();    
}

void displayField()
{
    int i, j;
    printf("+-----+\n");
    for (i = 0; i < 5; i++)
    {
        printf("|");
        for (j = 0; j < 5; j++)
        {
           printf("x"); // nanti diganti jadi isinya huft semangad bng
        }
        printf("|");
        printf("\n");
    }
    printf("+-----+");
}

int snakeOnMeteor()
{
    // KAMUS


    // ALGORITMA


}