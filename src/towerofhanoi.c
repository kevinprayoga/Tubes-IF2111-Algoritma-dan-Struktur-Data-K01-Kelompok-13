#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "towerofhanoi.h"
#include "function.h"

char* intToHanoi(int n){
    if (n == Nil){
        return "|";
    } else {
        char* result = (char*) malloc(sizeof(char) * n);
        int i;
        for (i = 0; i < n; i++){
            result[i] = '*';
        }
        result[i] = '\0';
        return result;
    }
}

char* intToAlas(int n){
    char* result = (char*) malloc(sizeof(char) * n);
    int i;
    for (i = 0; i < n; i++){
        result[i] = '-';
    }
    result[i] = '\0';
    return result;
}

void printAlas(int n, int length){
    int temp;
    if (n < 3){
        temp = 3;
    } else {
        if (n%2 == 0){
            temp = n + 1;
        } else {
            temp = n;
        }
    }
    int space = (length - stringLength(intToAlas(temp))) / 2;
    for (int i = 0; i < space; i++){
        printf(" ");
    }
    printf("%s", intToAlas(temp));
    for (int i = 0; i < space; i++){
        printf(" ");
    }
}

void show(Tower A, Tower B, Tower C, int n){
    printf("\n");
    int i = n - 1;
    int temp;
    int length = 2 * n + 1;
    while(i >= 0){
        printToMiddle(intToHanoi(A.T[i]), length);
        printToMiddle(intToHanoi(B.T[i]), length);
        printToMiddle(intToHanoi(C.T[i]), length);
        printf("\n");
        i--;
    }
    printToMiddle("A", length);
    printToMiddle("B", length);
    printToMiddle("C", length);
    printf("\n");
    printAlas(A.T[0], length);
    printAlas(B.T[0], length);
    printAlas(C.T[0], length);
    printf("\n");
}

void printToMiddle(char* str, int length){
    int i;
    int strLength;
    if (*str == '|' || *str == 'A' || *str == 'B' || *str == 'C'){
        strLength = 1;
    } else {
        strLength = stringLength(str);
    }
    int space = (length - strLength) / 2;
    for (i = 0; i < space; i++){
        printf(" ");
    }
    printf("%s", str);
    for (i = 0; i < space; i++){
        printf(" ");
    }
}

char wordToChar(Word K){
    return K.TabWord[0];
}

boolean isValid(Word K){
    return (K.Length == 1 && (K.TabWord[0] == 'A' || K.TabWord[0] == 'B' || K.TabWord[0] == 'C'));
}

boolean isWordNumber(Word K){
    int i = 0;
    boolean isNumber = true;
    while (isNumber && i < K.Length){
        isNumber = (K.TabWord[i] >= '0' && K.TabWord[i] <= '9');
        i++;
    }
    return isNumber;
}

int toh(){
    Tower A, B, C;
    Word command;
    char asal;
    char tujuan;
    int X, n;
    int move = 0;
    CreateEmptyTower(&A);
    CreateEmptyTower(&B);
    CreateEmptyTower(&C);
    printf("        __    __     _                            _\n");                 
    printf("       / / /\\ \\ \\___| | ___ ___  _ __ ___   ___  | |_ ___\n");           
    printf("       \\ \\/  \\/ / _ \\ |/ __/ _ \\| '_ ` _ \\ / _ \\ | __/ _ \\ \n");         
    printf("        \\  /\\  /  __/ | (_| (_) | | | | | |  __/ | || (_) | \n");        
    printf("         \\/  \\/ \\___|_|\\___\\___/|_| |_| |_|\\___|  \\__\\___/   \n\n");                                                                        
    printf(" _____                                __                           _ \n");
    printf("/__   \\_____      _____ _ __    ___  / _|   /\\  /\\__ _ _ __   ___ (_)\n");
    printf("  / /\\/ _ \\ \\ /\\ / / _ \\ '__|  / _ \\| |_   / /_/ / _` | '_ \\ / _ \\| |\n");
    printf(" / / | (_) \\ V  V /  __/ |    | (_) |  _| / __  / (_| | | | | (_) | |\n");
    printf(" \\/   \\___/ \\_/\\_/ \\___|_|     \\___/|_|   \\/ /_/ \\__,_|_| |_|\\___/|_|)\n\n");
    printf("Masukkan jumlah disk: ");
    STARTWORD();
    while (!isWordNumber(currentWord) || currentWord.TabWord[0] == '\0' || wordToInt(currentWord) > 100){
        printf("Masukkan tidak valid!\n");
        printf("\nMasukkan jumlah disk: ");
        STARTWORD();
    }
    printf("\nTekan ENTER untuk memulai permainan!\n");
    fgetchar();
    system("cls");
    n = wordToInt(currentWord);
    int disk = n;
    for (int i = 0; i < n; i++){
        PushTower(&A, 2*disk-1);
        disk--;
    }
    while (!(IsEmptyTower(A) && IsEmptyTower(B))){
        show(A, B, C, n);
        printf("\nTIANG ASAL : ");
        STARTWORD();
        if (strcompare(wordToString(currentWord), "QUIT")){
            printf("\nPermainan dihentikan!\n");
            return 0;
        }
        while (!isValid(currentWord) || currentWord.TabWord[0] == '\0'){
            printf("\nMasukkan tidak valid!\n");
            printf("\nTIANG ASAL : ");
            STARTWORD();
        }
        asal = currentWord.TabWord[0];
        currentWord.Length = 0;
        currentWord.TabWord[0] = '\0';
        printf("TIANG TUJUAN : ");
        STARTWORD();
        tujuan = currentWord.TabWord[0];
        if (isValid(currentWord) && (tujuan != asal)){
            boolean valid = true;
            if (asal == 'A' && !IsEmptyTower(A)){
                PopTower(&A, &X);
            } else if (asal == 'B' && !IsEmptyTower(B)){
                PopTower(&B, &X);
            } else if (asal == 'C' && !IsEmptyTower(C)) {
                PopTower(&C, &X);
            } else {
                valid = false;
                printf("\nTiang Asal Kosong!\n");
            }
            if (valid){
                if (tujuan == 'A' && (IsEmptyTower(A) || InfoTop(A) > X)){
                    PushTower(&A, X);
                } else if (tujuan == 'B' && (IsEmptyTower(B) || InfoTop(B) > X)){
                    PushTower(&B, X);
                } else if (tujuan == 'C' && (IsEmptyTower(C) || InfoTop(C) > X)){
                    PushTower(&C, X);
                } else {
                    printf("\nTiang tujuan tidak valid!\n");
                    if (asal == 'A'){
                        PushTower(&A, X);
                    } else if (asal == 'B'){
                        PushTower(&B, X);
                    } else if (asal == 'C'){
                        PushTower(&C, X);
                    }
                    valid = false;
                }
                if (valid){
                    printf("\nMemindahkan piringan ke %c...\n", tujuan);
                    move++;
                }
            }
        } else {
            printf("\nTiang tujuan tidak valid!\n");
        }
        currentWord.Length = 0;
        currentWord.TabWord[0] = '\0';
        }
    show(A,B,C,n);
    printf("\nKamu berhasil!\n");
    printf("\nSkor didapatkan = %.2f\n", scoring(n, move));
    return scoring(n, move);
}

float scoring(int n, int move){
    int i = 1;
    float disk = (float) n/5;
    for (int j = 1; j < n; j++) {
        i *= 2;
        i++;
    }
    return (((float)i/(float)move) * (float)10 * disk);
}