#include "dinerdash.h"

void show(QueueFood q1, QueueCook q2, int saldo) {
    int i;
    printf("\nSALDO: %ld\n", saldo);
    printf("\nDaftar Pesanan\n");
    printf("Makanan | Durasi memasak | Ketahanan | Harga\n");
    printf("----------------------------------------------\n");
    for(i = IDX_HEAD(q1); i <= IDX_TAIL(q1); i++){
        printf("M%d      | %d              | %d         | %d    \n",(q1).buffer[i].id , (q1).buffer[i].time, (q1).buffer[i].expired, (q1).buffer[i].price);
    }
    printf("\nDaftar Makanan yang sedang dimasak\n");
    printf("Makanan\t| Sisa durasi memasak\t\n");
    printf("-----------------------------\n");
    int j;
    if (!(isEmptyCook(q2))){
        for (j = IDX_HEAD(q2); j <= IDX_TAIL(q2); j++){
            if (q2.buffer[j].cookLeft != 0){
                printf("M%d      | %d\n", (q2).buffer[j].id, (q2).buffer[j].cookLeft);
            }
        }
    }
    printf("\nDaftar Makanan yang dapat disajikan\n");
    printf("Makanan\t| Sisa ketahanan makanan\t\n");
    printf("--------------------------------\n");
    int k; 
    if (!(isEmptyCook(q2))){
        for(k = IDX_HEAD(q2); k <= IDX_TAIL(q2); k++){
            if (q2.buffer[k].cookLeft == 0 && q2.buffer[k].serveLeft && q2.buffer[k].serveLeft != -999){
                printf("M%d      | %d\n", (q2).buffer[k].id, (q2).buffer[k].serveLeft);
            }
        } 
    }
}

void orderFood(QueueFood* q, int idx){
    Food val;
    val.id = idx;
    val.time = rand()%4 + 1;
    val.expired = rand()%4 + 1;
    val.price = rand()%40 *1000 + 10000;
    enqueueFood(q, val);
}

int cookCapacity(QueueCook q){
    int ctr = 0;
    for (int i = IDX_HEAD(q); i <= IDX_TAIL(q); i++){
        if (q.buffer[i].cookLeft != 0){
            ctr++;
        }
    }
}

boolean isWordSame(Word command1, Word command2){
    int i = 0;
    boolean same = true;
    int max = command1.Length;
    if (max < command2.Length){
        max = command2.Length;
    }
    while (i < max  && same){
        if (command1.TabWord[i] != command2.TabWord[i]){
            same = false;
        }
        i++;
    }
    return same;
}

boolean isFoodFormat(Word food){
    boolean isFood = true;
    if (food.Length == 2){
        if (food.TabWord[0] != 'M'){
            isFood = false;
        } else {
            if (food.TabWord[1] < '0' || food.TabWord[1] > '9'){
                isFood = false;
            }
        }
    } else if (food.Length == 3){
        if (food.TabWord[0] != 'M'){
            isFood = false;
        } else {
            if (food.TabWord[1] < '0' || food.TabWord[1] > '9'){
                isFood = false;
            } else {
                if (food.TabWord[2] < '0' || food.TabWord[2] > '9'){
                    isFood = false;
                }
            }
        }
    } else {
        isFood = false;
    }
    return isFood;
}

int foodtonum(Word food){
    int num = 0;
    if (food.Length == 2){
        num = food.TabWord[1] - '0';
    } else if (food.Length == 3){
        num = (food.TabWord[1] - '0') * 10 + (food.TabWord[2] - '0');
    }
    return num;
}

int searchIndexIdFood(QueueFood q, int id){
    int i = IDX_HEAD(q);
    boolean found = false;
    while (i <= IDX_TAIL(q) && !found){
        if (q.buffer[i].id == id){
            found = true;
        } else {
            i++;
        }
    }
    if (found){
        return i;
    } else {
        return -1;
    }
}

void checkCook(QueueCook* q){
    int i = IDX_HEAD(*q);
    while (i <= IDX_TAIL(*q)){
        if ((*q).buffer[i].cookLeft != 0){
            (*q).buffer[i].cookLeft--;
        }
        else{
            if ((*q).buffer[i].serveLeft > 0){
                (*q).buffer[i].serveLeft--;
            }
        }
        i++;
    }
}

int searchIndexIdCook(QueueCook q, int id){
    int i = IDX_HEAD(q);
    boolean found = false;
    while (i <= IDX_TAIL(q) && !found){
        if (q.buffer[i].id == id){
            if (q.buffer[i].serveLeft != -999){
                found = true;
            } else {
                i++;
            }
        } else {
            i++;
        }
    }
    if (found){
        return i;
    } else {
        return -1;
    }
}

Word getFirstWord(Word word){
    Word firstWord;
    int i = 0;
    while (word.TabWord[i] != ' ' && i < word.Length){
        firstWord.TabWord[i] = word.TabWord[i];
        i++;
    }
    firstWord.Length = i;
    return firstWord;
}

Word getSecondWord(Word word){
    Word secondWord;
    int i = 0;
    while (word.TabWord[i] != ' ' && i < word.Length){
        i++;
    }
    i++;
    int j = 0;
    while (i < word.Length){
        secondWord.TabWord[j] = word.TabWord[i];
        i++;
        j++;
    }
    secondWord.Length = j;
    return secondWord;
}

Cook cookFood(QueueFood q, int i){
    Cook food;
    food.id = (q).buffer[i].id;
    food.cookLeft = (q).buffer[i].time;
    food.serveLeft = (q).buffer[i].expired;
    return food;
}



void dinerdash(){
    QueueFood qfood;
    QueueCook qcook;
    CreateQueueFood(&qfood);
    CreateQueueCook(&qcook);

    Food food;
    Cook cook;
    Cook temp;

    Word commandCook;
    commandCook.Length = 4;
    commandCook.TabWord[0] = 'C';
    commandCook.TabWord[1] = 'O';
    commandCook.TabWord[2] = 'O';
    commandCook.TabWord[3] = 'K';
    

    Word commandServe;
    commandServe.Length = 5;
    commandServe.TabWord[0] = 'S';
    commandServe.TabWord[1] = 'E';
    commandServe.TabWord[2] = 'R';
    commandServe.TabWord[3] = 'V';
    commandServe.TabWord[4] = 'E';

    Word commandSkip;
    commandSkip.Length = 4;
    commandSkip.TabWord[0] = 'S';
    commandSkip.TabWord[1] = 'K';
    commandSkip.TabWord[2] = 'I';
    commandSkip.TabWord[3] = 'P';

    int serve = 0;
    int saldo = 0;
    int id = 0;
    int idx;
    int cookorserve;

    boolean putaran = false;
    boolean masak = false;

    for(id = 0; id < 3; id++){
        orderFood(&qfood, id);    
    }

    while ((serve < 10) && (lengthFood(qfood) < 10)){
        if (putaran){
            orderFood(&qfood, id);
            id++;
            checkCook(&qcook);
            if (masak){
                enqueueCook(&qcook, temp);
                masak = false;
            }
        }
        putaran = false;
        show(qfood, qcook, saldo);
        printf("\nCOMMAND : ");
        STARTWORD();



        if (isWordSame(commandCook, getFirstWord(currentWord))){
            if (isFoodFormat(getSecondWord(currentWord))){
                idx = foodtonum(getSecondWord(currentWord));
                if (searchIndexIdFood(qfood,idx) != -1) {
                    if (cookCapacity(qcook) <= 5){
                        temp = cookFood(qfood, searchIndexIdFood(qfood,idx));                   
                        putaran = true;
                        masak = true;
                        printf("\nBerhasil memasak makanan M%d\n", idx);
                        printf("========================================\n");
                    } else{
                        printf("\nAntrian memasak sudah penuh\n");
                        printf("========================================\n");
                    }
                } else {
                    printf("\nMAKANAN TIDAK TERSEDIA\n");
                    printf("========================================\n");
                }
            } else{
                printf("\nCOMMAND TIDAK VALID\n");
                printf("========================================\n");
            }
        } else if (isWordSame(commandServe, getFirstWord(currentWord))){ //else dari isWordSame(commandCook, currentWord)
            ADVWORD();
            if(isFoodFormat(getSecondWord(currentWord))){
                idx = foodtonum(getSecondWord(currentWord));
                if (searchIndexIdCook(qcook, idx) != -1){
                    if (qcook.buffer[searchIndexIdCook(qcook, idx)].cookLeft == 0){
                        if (qfood.buffer[IDX_HEAD(qfood)].id == idx){
                            saldo += qfood.buffer[searchIndexIdFood(qfood, idx)].price;
                            qcook.buffer[searchIndexIdCook(qcook, idx)].serveLeft = -999;
                            dequeueFood(&qfood);
                            serve++;
                            putaran = true;
                            printf("\nBerhasil mengantar M%d\n", foodtonum(getSecondWord(currentWord)));
                            printf("===============================================\n");        
                        } else if (qfood.buffer[IDX_HEAD(qfood)].id > idx) {
                            printf("\nMakanan telah disajikan sebelumnya\n");
                            printf("===============================================\n");
                            putaran = true;
                        } else{
                            printf("\nM%d belum dapat disajikan karena M%d belum selesai\n", foodtonum(getSecondWord(currentWord)), foodtonum(getSecondWord(currentWord)) - 1);
                            printf("===============================================\n");
                        }
                    } else {
                        printf("\nMAKANAN BELUM SIAP\n");
                        printf("========================================\n");
                    }
                } else {
                    printf("\nMAKANAN TIDAK TERSEDIA\n");
                    printf("========================================\n");
                }
            } else {
                printf("\nCOMMAND TIDAK VALID\n");
                printf("========================================\n");
            }
        } else if (isWordSame(commandSkip, getFirstWord(currentWord))){
            printf("\nKamu melewati giliran\n");
            printf("========================================\n");
            putaran = true;
        } else {
            printf("\nCOMMAND TIDAK VALID\n");
            printf("========================================\n");
        } //else dari ngecek command
    }
    printf("\nGAME OVER\n");
}

/*
    printf("Selamat Datang di Diner Dash!\n");
    while (serve < 15 && lengthFood(qfood) < 15){
        show(qfood, qcook, saldo);
        if (putaran == true){
            checkCook(&qcook);
        }
        putaran = false;
        printf("\nMASUKKAN COMMAND: ");
        STARTWORD();
        if ((isWordSame(commandCook, currentWord) || isWordSame(commandServe, currentWord))){
            if (isWordSame(commandCook, currentWord)){
                cookorserve = 1;
            } else if (isWordSame(commandServe, currentWord)){
                cookorserve = 2;
            } else {
                cookorserve = 0;
            }
            if (!(IsEOP())){
                ADVWORD();
                if (isFoodFormat(currentWord)){
                if ((searchIndexIdFood(qfood, foodtonum(currentWord)) != -1) || (searchIndexIdCook(qcook, foodtonum(currentWord)) != -1)){
                    if (cookorserve == 1){
                        idx = searchIndexIdFood(qfood, foodtonum(currentWord));
                        enqueueCook(&qcook, cookFood(qfood, idx));
                        printf("\nBerhasil memasak M%d\n", foodtonum(currentWord));
                        printf("===============================================\n");
                    } else if (cookorserve == 2){
                        idx = searchIndexIdCook(qcook, foodtonum(currentWord));
                        if (qcook.buffer[idx].cookLeft == 0 && searchIndexIdCook(qcook, foodtonum(currentWord) != -1 )){
                            if (qfood.buffer[IDX_HEAD(qfood)].id == qcook.buffer[idx].id){
                                qcook.buffer[idx].serveLeft = 999;
                                idx = searchIndexIdFood(qfood, foodtonum(currentWord));
                                saldo += qfood.buffer[idx].price;
                                printf("\nBerhasil mengantar M%d\n", foodtonum(currentWord));
                                printf("===============================================\n");
                                dequeueFood(&qfood);
                                serve++;
                            } else if(qcook.buffer[idx].id > qfood.buffer[IDX_HEAD(qfood)].id){
                                printf("\nM%d belum dapat disajikan karena M%d belum selesai\n", foodtonum(currentWord), foodtonum(currentWord) - 1);
                                printf("===============================================\n");
                            }else{
                                printf("\nMakanan telah disajikan sebelumnya\n");
                                printf("===============================================\n");
                            }
                        }    
                    }
                    orderFood(&qfood, id);
                    id++;
                    putaran = true;
                } else{
                    printf("\nCOMMAND TIDAK VALID\n");
                    printf("===============================================\n");
                }
            } else{
                printf("\nCOMMAND TIDAK VALID\n");
                printf("===============================================\n");
            }
                
            }
            
        } else if (isWordSame(commandSkip, currentWord)){
            printf("\nBerhasil melewati putaran\n");
            printf("===============================================\n");
            orderFood(&qfood, id);
            id++;
            putaran = true;
        } else{
            printf("\nCOMMAND TIDAK VALID\n");
            printf("===============================================\n");
        }
    }
    show(qfood, qcook, saldo);
    printf("\nGAME OVER\n");
}
*/
