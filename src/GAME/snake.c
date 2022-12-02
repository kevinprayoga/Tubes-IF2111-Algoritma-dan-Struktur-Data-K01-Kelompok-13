#include "snake.h"

void asciisnake(){
    printf("000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000\n");
    printf("000000000000000000D7~~O000000@77M00000000000000000___0000000000___0000000000___0000000000___000000000___0000000000000000000000000000\n");
    printf("000000000000000005 zrz,_700~_=zz_^000000000000000/00/\\00000000/__/\\00000000/00/\\00000000/__/|0000000/00/\\000000000000000000000000000\n");
    printf("00000000000000000 |\" _`7c__y?`_`7,\"0000000000000/00/:/_0000000\\00\\:\\000000/00/::\\000000|00|:|000000/00/:/_00000000000000000000000000\n");
    printf("00000000000000000 | <0- LLL{ L0? <.000000000000/00/:/0/\\0000000\\00\\:\\0000/00/:/\\:\\00000|00|:|00000/00/:/0/\\0000000000000000000000000\n");
    printf("0000000000000000F z_  , >LL, ,  ,z Q0000000000/00/:/0/::\\00_____\\__\\:\\00/00/:/~/::\\00__|00|:|0000/00/:/0/:/_000000000000000000000000\n");
    printf("0000000000000000-='\"z__,LLLL,__/\"\"z 000000000/__/:/0/:/\\:\\/__/::::::::\\/__/:/0/:/\\:\\/__/\\_|:|___/__/:/0/:/0/\\00000000000000000000000\n");
    printf("0000000000000000,-<_\"LLLLLLLLLL\" / y000000000\\00\\:\\/:/~/:/\\00\\:\\~~\\~~\\/\\00\\:\\/:/__\\/\\00\\:\\/:::::|00\\:\\/:/0/:/00000000000000000000000\n");
    printf("0000000000000000D,`\\-`<\"\"L7'7<' '_p00000000000\\00\\::/0/:/00\\00\\:\\00~~~00\\00\\::/000000\\00\\::/~~~~0\\00\\::/0/:/000000000000000000000000\n");
    printf("000000000000000000bg,_ '\\<</' ,yp00000000000000\\__\\/0/:/0000\\00\\:\\0000000\\00\\:\\0000000\\00\\:\\000000\\00\\:\\/:/0000000000000000000000000\n");
    printf("000000000000000000000 ;\\,__ y00000000000000000000/__/:/000000\\00\\:\\0000000\\00\\:\\0000000\\00\\:\\000000\\00\\::/00000000000000000000000000\n");
    printf("000000000000000000000 CL<<< 000000000000000000000\\__\\/00000000\\__\\/00000000\\__\\/00000000\\__\\/0000000\\__\\/000000000000000000000000000\n");
    printf("00000000000000000000& 5L{<'.00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000\n");
    printf("00000000000000000000R CL}<,-000000000000000000000000000000000000000000___0000000000___0000000000000000000000000000000000000000000000\n");
    printf("000000000000000000000 7L5<< B0000000000000000000000000000000000000000/00/\\00000000/__/\\000000000000000000000000000000000000000000000\n");
    printf("0000000000000000000005 LL<<, B00000000000000000000000000000000000000/00/::\\0000000\\00\\:\\00000000000000000000000000000000000000000000\n");
    printf("00000000000000000000000,'L}<<\\_\"000000000000000000000000000000000000/00/:/\\:\\0000000\\00\\:\\000000000000000000000000000000000000000000\n");
    printf("00000000000000000000000,'7<<<<,_~700000000000000000000000000000000/00/:/00\\:\\00_____\\__\\:\\000000000000000000000000000000000000000000\n");
    printf("000000000000000000000000c \"<<<<<\\,_`~7000000000000000000000000000/__/:/0\\__\\:\\/__/::::::::\\00000000000000000000000000000000000000000\n");
    printf("0000000000000000000000000,_'\\<<<<<<\\- `7000000000000000000000000\\00\\:\\0/00/:/\\00\\:\\~~\\~~\\/000000000000000000000000000000000000000000\n");
    printf("0000000000000000000000MC7~~^  _____,,,,,,__~W000000000000000000000\\00\\:\\00/:/00\\00\\:\\00~~~000000000000000000000000000000000000000000\n");
    printf("00000000000000000F~`_,=zzwLZ77LLLLLLLLLLLL7z_\"000000000000000000000\\00\\:\\/:/0000\\00\\:\\0000000000000000000000000000000000000000000000\n");
    printf("000000000000000F ,r77{<<<<<<<<<<<<<<<<<<<<<<< B000000000000000000000\\00\\::/000000\\00\\:\\000000000000000000000000000000000000000000000\n");
    printf("000000000000000 /<<<<<<<<<<<<<<<>\\\"\"~~''~~\"\"\\ B0000000000000000000000\\__\\/00000000\\__\\/000000000000000000000000000000000000000000000\n");
    printf("000000000000000 \"~'''``   _____,,,==zzzzzzz=,_~B000000000000000000000000000000000000000000000000000000000000000000000000000000000000\n");
    printf("0000000000000^_,=zwwCZZZ777L777{{{<<<<<<<<<{77z 000000000000___0000000000___00000000000000000___0000000000___0000000000___0000000000\n");
    printf("000000000000 /LL77{<<<<<<<<<<<<<<<<<<<<<<<<<<<< Q0000000000/__/\\00000000/00/\\00000000___0000/00/\\00000000/00/\\00000000/00/\\000000000\n");
    printf("0000000000@Z \"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>\" ,@000000000|00|::\\000000/00/:/_000000/00/\\00/00/:/_000000/00/::\\000000/00/::\\00000000\n");
    printf("000000000ZZZL_ '\"<<<<<<<<<<<<<<<<<<<<>/\"~'`_,, 7ZZB0000000|00|:|:\\0000/00/:/0/\\0000/00/:/0/00/:/0/\\0000/00/:/\\:\\0000/00/:/\\:\\0000000\n");
    printf("000000000ZZZZZLg,,__ ``'`````    ____,,=yg 5<<.-ZZB00000__|__|:|\\:\\00/00/:/0/:/_00/00/:/0/00/:/0/:/_00/00/:/00\\:\\00/00/:/~/:/0000000\n");
    printf("0000000000@GZZZZZZZZZZZLLLLLZZZZZZZZZZZZZ^,5<< ;@000000/__/::::|0\\:\\/__/:/0/:/0/\\/00/::\\/__/:/0/:/0/\\/__/:/0\\__\\:\\/__/:/0/:/___00000\n");
    printf("00000000000000@@GZZZZZZZZZZZZZZZZZZZZZZ7`,{\"' y00000000\\00\\:\\~~\\__\\/\\00\\:\\/:/0/:/__/:/\\:\\00\\:\\/:/0/:/\\00\\:\\0/00/:/\\00\\:\\/:::::/00000\n");
    printf("00000000000000000000000@@@@@@@@@@@@@00`_/`_=p00000000000\\00\\:\\0000000\\00\\::/0/:/\\__\\/00\\:\\00\\::/0/:/00\\00\\:\\00/:/00\\00\\::/~~~~000000\n");
    printf("0000000000000000000000000000000000000'-`,0000000000000000\\00\\:\\0000000\\00\\:\\/:/000000\\00\\:\\00\\:\\/:/0000\\00\\:\\/:/0000\\00\\:\\0000000000\n");
    printf("0000000000000000000000000000000000000gy0000000000000000000\\00\\:\\0000000\\00\\::/00000000\\__\\/\\00\\::/000000\\00\\::/000000\\00\\:\\000000000\n");
    printf("00000000000000000000000000000000000000000000000000000000000\\__\\/00000000\\__\\/000000000000000\\__\\/00000000\\__\\/00000000\\__\\/000000000\n\n");
}

void generateMeteor(point *meteor, point *obstacle1, point *obstacle2, point *food, List snake, boolean *dead)
{
    // KAMUS
    addressLinked p = First(snake);
    point head;

    // ALGORITMA
    srand(time(NULL));
    CreatePoint(meteor, rand() % 5, rand() % 5);
    do {
        srand(rand());
        CreatePoint(meteor, rand() % 5, rand() % 5);
    } while (isPointEq(*meteor, *obstacle1) || isPointEq(*meteor, *obstacle2) || isPointEq(*meteor, *food));
    CreatePoint(&head, InfoX(First(snake)), InfoY(First(snake)));
    if (isPointEq(*meteor, head))
    {
        *dead = true;
    }
}

void generateFood(point meteor, point obstacle1, point obstacle2, point *food, List snake)
{
    // KAMUS

    // ALGORITMA
    srand(time(NULL));
    do {
        srand(rand());
        CreatePoint(food, rand() % 5, rand() % 5);
    } while (isPointEq(*food, obstacle1) || isPointEq(*food, obstacle2) || isPointEq(*food, meteor) || (Search(snake, *food) != Niln));
}

point generateObstacle(point obstacle)
{
    // KAMUS
    point obs2;
    boolean drop = false;

    // ALGORITMA
    srand(time(NULL));
    do {
        srand(rand());
        CreatePoint(&obs2, rand() % 5, rand() % 5);
    } while (isPointEq(obs2, obstacle));

    return obs2;
}

void generateHead(point *obstacle1, point *obstacle2, List *snake)
{
    // KAMUS
    boolean drop = false;
    point head;

    // ALGORITMA
    srand(time(NULL));
    do {
        srand(rand());
        CreatePoint(&head, rand() % 5, rand() % 5);
    } while (isPointEq(head, *obstacle1) || isPointEq(head, *obstacle2));
    InsVFirst(snake, head);
}

void growSnake(List *snake, point *obstacle1, point *obstacle2, point *meteor, boolean *dead)
{
    // KAMUS
    point grow;
    addressLinked adrTail = First(*snake);
    boolean add = true;

    // ALGORITMA
    // cari tail
    while (Next(adrTail) != Niln)
    {
        adrTail = Next(adrTail);
    }

    CreatePoint(&grow, InfoX(adrTail) - 1, InfoY(adrTail)); // bikin di sebelah kiri dari tail
    teleport(&grow); // supaya bisa nembus field
    if (isPointEq(grow, *obstacle1) || isPointEq(grow, *obstacle2) || isPointEq(grow, *meteor) || (Search(*snake, grow) != Niln))
    {
        CreatePoint(&grow, InfoX(adrTail), InfoY(adrTail) - 1); // atas
        teleport(&grow);
        if (isPointEq(grow, *obstacle1) || isPointEq(grow, *obstacle2) || isPointEq(grow, *meteor) || (Search(*snake, grow) != Niln))
        {
            CreatePoint(&grow, InfoX(adrTail), InfoY(adrTail) + 1); // bawah
            teleport(&grow);
            if (isPointEq(grow, *obstacle1) || isPointEq(grow, *obstacle2) || isPointEq(grow, *meteor) || (Search(*snake, grow) != Niln))
            {
                CreatePoint(&grow, InfoX(adrTail) + 1, InfoY(adrTail)); // kanan
                teleport(&grow);
                if (isPointEq(grow, *obstacle1) || isPointEq(grow, *obstacle2) || isPointEq(grow, *meteor) || (Search(*snake, grow) != Niln))
                {
                    *dead = true;
                    add = false;
                    printf("Ekor tidak bisa tumbuh:(\n");
                }
            }
        }
    }
    if (add)
    {
        InsVLast(snake, grow);
    }
}

boolean isValidInput(char *cmd, List snake, point *meteor)
{
    // KAMUS
    point loc;

    // ALGORITMA

    if (strcompare("w", cmd) || strcompare("W", cmd))
    {
        CreatePoint(&loc, InfoX(First(snake)), InfoY(First(snake)) - 1);
        // displayPoint(loc);
        teleport(&loc);
        // displayPoint(loc);
        addressLinked search = Search(snake, loc);
        // jika w menyebabkan head menabrak meteor atau dirinya sendiri, program harus minta input ulang
        if (isPointEq(loc, *meteor))
        {
            printf("Meteor masih panas, Anda belum dapat kembali ke titik tersebut.\n");
            return false;
        }
        else if (search != Niln)
        {
            printf("Anda tidak dapat bergerak ke tubuh Anda sendiri!\n");
            return false;
        }
        else
        {
            return true;
        }
    }
    else if (strcompare("a", cmd) || strcompare("A", cmd))
    {
        CreatePoint(&loc, InfoX(First(snake)) - 1, InfoY(First(snake)));
        // displayPoint(loc);
        teleport(&loc);
        // displayPoint(loc);
        addressLinked search = Search(snake, loc);
        // jika a menyebabkan head menabrak meteor atau dirinya sendiri, program harus minta input ulang
        if (isPointEq(loc, *meteor))
        {
            printf("Meteor masih panas, Anda belum dapat kembali ke titik tersebut.\n");
            return false;
        }
        else if (search != Niln)
        {
            printf("Anda tidak dapat bergerak ke tubuh Anda sendiri!\n");
            return false;
        }
        else
        {
            return true;
        }
    }
    else if (strcompare("s", cmd) || strcompare("S", cmd))
    {
        CreatePoint(&loc, InfoX(First(snake)), InfoY(First(snake)) + 1);
        teleport(&loc);
        addressLinked search = Search(snake, loc);
        // jika s menyebabkan head menabrak meteor atau dirinya sendiri, program harus minta input ulang
        if (isPointEq(loc, *meteor))
        {
            printf("Meteor masih panas, Anda belum dapat kembali ke titik tersebut.\n");
            return false;
        }
        else if (search != Niln)
        {
            printf("Anda tidak dapat bergerak ke tubuh Anda sendiri!\n");
            return false;
        }
        else
        {
            return true;
        }
    }
    else if (strcompare("d", cmd) || strcompare("D", cmd))
    {
        CreatePoint(&loc, InfoX(First(snake)) + 1, InfoY(First(snake)));
        teleport(&loc);
        addressLinked search = Search(snake, loc);
        // jika d menyebabkan head menabrak meteor atau dirinya sendiri, program harus minta input ulang
        if (isPointEq(loc, *meteor))
        {
            printf("Meteor masih panas, Anda belum dapat kembali ke titik tersebut.\n");
            return false;
        }
        else if (search != Niln)
        {
            printf("Anda tidak dapat bergerak ke tubuh Anda sendiri!\n");
            return false;
        }
        else
        {
            return true;
        }
    }
    else
    {
        // selain WASD/wasd input tidak valid
        return false;
    }
}

void moveSnake(char *cmd, List *snake)
{
    // KAMUS
    point move, dump;

    // ALGORITMA
    if (strcompare("w", cmd) || strcompare("W", cmd))
    {
        CreatePoint(&move, InfoX(First(*snake)), InfoY(First(*snake)) - 1);
    }
    else if (strcompare("s", cmd) || strcompare("S", cmd))
    {
        CreatePoint(&move, InfoX(First(*snake)), InfoY(First(*snake)) + 1);
    }
    else if (strcompare("a", cmd) || strcompare("A", cmd))
    {
        CreatePoint(&move, InfoX(First(*snake)) - 1, InfoY(First(*snake)));
    }
    else if (strcompare("d", cmd) || strcompare("D", cmd))
    {
        CreatePoint(&move, InfoX(First(*snake)) + 1, InfoY(First(*snake)));
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
    return (Search(snake, meteor) != Niln); // kalau != Niln berarti ketemu, artinya nabrak
}

void collideMeteor(List snake, point *meteor, boolean *dead)
{
    if (isPointEq(*meteor, Info(First(snake))))
    {
        printf("Kepala snek terkena meteor!:(\n");
        *dead = true;
    }
    else
    {
        DelP(&snake, *meteor);
        printf("Snek nabrak meteor!:(\n");
    }
}

boolean isCollideObstacle(List snake, point obstacle1, point obstacle2)
{
    return ((Search(snake, obstacle1) != Niln) || (Search(snake, obstacle2) != Niln));
}

void collideObstacle(List snake, point *obstacle1, point *obstacle2, boolean *dead)
{
    printf("Mati nabrak obstacle:(\n");
    *dead = true;
}

boolean cantMove(List snake, point *obstacle1, point *obstacle2, point *meteor, boolean *dead)
{
    // KAMUS
    int count = 0;
    point move;

    // ALGORITMA
    // cek atas
    CreatePoint(&move, InfoX(First(snake)), InfoY(First(snake)) - 1);
    teleport(&move);
    if (isPointEq(move, *obstacle1) || isPointEq(move, *obstacle2) || isPointEq(move, *meteor) || Search(snake, move) != Niln)
    {
        count++;
    }
    // cek bawah
    CreatePoint(&move, InfoX(First(snake)), InfoY(First(snake)) + 1);
    teleport(&move);
    if (isPointEq(move, *obstacle1) || isPointEq(move, *obstacle2) || isPointEq(move, *meteor) || Search(snake, move) != Niln)
    {
        count++;
    }
    // cek kiri
    CreatePoint(&move, InfoX(First(snake)) - 1, InfoY(First(snake)));
    teleport(&move);
    if (isPointEq(move, *obstacle1) || isPointEq(move, *obstacle2) || isPointEq(move, *meteor) || Search(snake, move) != Niln)
    {
        count++;
    }
    // cek kanan
    CreatePoint(&move, InfoX(First(snake)) + 1, InfoY(First(snake)));
    teleport(&move);
    if (isPointEq(move, *obstacle1) || isPointEq(move, *obstacle2) || isPointEq(move, *meteor) || Search(snake, move) != Niln)
    {
        count++;
    }
    return (count == 4); // jika count = 4, berarti tidak ada tempat untuk bergerak
}

void displayField(List snake, point meteor, point food, point obstacle1, point obstacle2)
{
    // KAMUS
    point loc;
    int i, j;
    int field[5][5];
    addressLinked p;

    // ALGORITMA
    // supaya tubuh snek displaynya 1,2,dst.
    p = First(snake);
    i = 1;
    while (p != Niln)
    {
        if (p != First(snake))
        {
            field[InfoY(p)][InfoX(p)] = i;
            i++;
        }
        p = Next(p);
    }
    // tampilan field asli
    printf("\n+---+---+---+---+---+\n");
    for (i = 0; i < 5; i++)
    {
        printf("|");
        for (j = 0; j < 5; j++)
        {
            // ini ceritanya bikin point dari setiap titik pada field
            // kalau pointnya merupakan head, dia print H, dst...
            CreatePoint(&loc, j, i);
            if (isPointEq(loc, meteor))
            {
                printf(" M |");
            }
            else if (isPointEq(loc, obstacle1) || isPointEq(loc, obstacle2))
            {
                printf(" # |");
            }
            else if (isPointEq(loc, food))
            {
                printf(" O |");
            }
            else if (isPointEq(loc, Info(First(snake))))
            {
                printf(" H |");
            }
            else if (Search(snake, loc) != Niln)
            {
                printf(" %d |", field[i][j]);
            }
            else
            {
                printf("   |");
            }
        }
        printf("\n+---+---+---+---+---+\n");
    }
}

int snekOnMeteor()
{
    // KAMUS
    List snake;
    point meteor, obstacle1, obstacle2, food;
    boolean dead = false;
    int score;
    char *moveCmd;

    // ALGORITMA
    // generate field awal: snek, obstacle, makanan
    asciisnake();
    printf("Selamat datang di Snek on Meteor!\n");
    printf("Mengenerate peta, snek, obstacle, dan makanan...\n");
    printf("Berhasil di-generate!\n");
    CreatePointNil(&meteor);
    srand(time(0));
    CreatePoint(&obstacle1, rand() % 5, rand() % 5);
    obstacle2 = generateObstacle(obstacle1);
    CreateEmpty(&snake);
    generateHead(&obstacle1, &obstacle2, &snake);
    growSnake(&snake, &obstacle1, &obstacle2, &meteor, &dead);
    growSnake(&snake, &obstacle1, &obstacle2, &meteor, &dead);
    CreatePointNil(&food);
    generateFood(meteor, obstacle1, obstacle2, &food, snake);
    // main sampai game over
    while (!dead)
    {
        if (cantMove(snake, &obstacle1, &obstacle2, &meteor, &dead))
        {
            printf("Snek tidak dapat bergerak!:(\n");
            break;
        }
        displayField(snake, meteor, food, obstacle1, obstacle2);
        // input command
        moveCmd = inputCmd();
        if (isValidInput(moveCmd, snake, &meteor))
        {
            printf("Berhasil bergerak!\n");
            moveSnake(moveCmd, &snake);
            generateMeteor(&meteor, &obstacle1, &food, &obstacle2, snake, &dead);
            if (isPointEq(Info(First(snake)), food))
            {
                printf("Snek makan\n");
                growSnake(&snake, &obstacle1, &obstacle2, &meteor, &dead);
                generateFood(meteor, obstacle1, obstacle2, &food, snake);
            }
            if (isCollideMeteor(snake, meteor))
            {
                collideMeteor(snake, &meteor, &dead);
            }
            if (isCollideObstacle(snake, obstacle1, obstacle2))
            {
                collideObstacle(snake, &obstacle1, &obstacle2, &dead);
            }
            if (isPointEq(Info(First(snake)), food))
            {
                printf("Snek makan\n");
                growSnake(&snake, &obstacle1, &obstacle2, &meteor, &dead);
                generateFood(meteor, obstacle1, obstacle2, &food, snake);
            }
        }
        else
        {
            printf("Input tidak valid!\nSilakan masukkan command yang lain.\n");
        }
        currentWord.Length = 0;
    }

    displayField(snake, meteor, food, obstacle1, obstacle2);
    score = NbElmt(snake) * 2;
    if (isPointEq(meteor, Info(First(snake))))
    {
        score = (NbElmt(snake) - 1) * 2;
    }
    printf("Game over!\n\nSkor: %d\n", score);

    return score;
}