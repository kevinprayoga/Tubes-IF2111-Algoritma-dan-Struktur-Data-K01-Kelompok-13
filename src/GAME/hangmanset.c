#include "hangmanset.h"
#include "../console.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void loadkata(SetStr *S){
    STARTFILE("../data/hangman.txt");
    ADVWORDFILE();
    char *strnum = wordToString(currentWord);
    int num = strToInt(strnum);
    if (num > 0)
    {
        ADVFILE();
        for (int i = 0; i < num; i++)
        {
        ADVWORDFILE();
        char *name = wordToString(currentWord);
        InsertSetStr(S, name);
        }
    }
}

void printSet(SetChar S){
    for (int i = 0; i < S.Count; i++)
    {
        printf("%c", S.Elements[i]);
    }
    printf("\n");
}

void hangmanset(int* score){
    srand(time(0));
    int guessctr = 0;
    boolean gotright = false;
    char* tebakan;
    SetChar guess;
    SetStr kata;
    *score = 0;
    CreateEmptySetStr(&kata);
    loadkata (&kata);
    while (!IsEmptySetStr(kata) && guessctr < 10){
        tebakan = kata.Elements[rand()%kata.Count];
        DeleteSetStr(&kata, tebakan);
        CreateEmptySetChar(&guess);
        while (guessctr < 10 && !gotright){
            gotright = true;
            if (IsEmptySetChar(guess)){
                printf("Tebakan sebelumnya: -\n");
            } else {
                printf("Tebakan sebelumnya: ");
                printSet(guess);
                printf("\n");
            }
            for (int i = 0; i < strlength(tebakan); i++){
                if (IsMemberSetChar(guess, tebakan[i])){
                    printf("%c ", tebakan[i]);
                } else {
                    printf("_ ");
                }
            }
            printf("\nKesempatan: %d\n", 10-guessctr);
            printf("Masukkan tebakan: ");
            STARTWORD();
            while (currentWord.Length != 1 || IsMemberSetChar(guess, currentWord.TabWord[0])){
                printf("Karakter tidak valid!\n");
                printf("\nMasukkan tebakan: ");
                STARTWORD();
            }
            if (IsMemberChar(tebakan, currentWord.TabWord[0])){
                InsertSetChar(&guess, currentWord.TabWord[0]);
            } else {
                InsertSetChar(&guess, currentWord.TabWord[0]);
                guessctr++;
            }

            printf("\n");
            currentWord.Length = 0;
            for (int i = 0; i < strlength(tebakan); i++){
                if (! IsMemberSetChar(guess, tebakan[i])){
                    gotright = false;
                }
            }
        }
        if (guessctr < 10){
            printf("Berhasil menebak %s! Kamu mendapat 4 poin!\n\n", tebakan);
            *score += 4;
            gotright = false;
        }
    }
    if (guessctr == 10){
        printf("Kamu gagal menebak kata. Kata tebakan adalah %s.\n", tebakan);
    }
    printf("\nGame Over!\n\nSkor anda = %d\n", *score);
}

void saveKata(){
    FILE *file;
    SetStr listKata;
    int i;
    CreateEmptySetStr(&listKata);
    loadkata (&listKata);
    printf("\nKetik 'q' jika ingin membatalkan.\n");
    printf("Masukkan kata baru : ");
    STARTWORD();
    while(IsMemberSetStr(listKata, wordToString(currentWord)) == true){
        printf("\nKata tidak valid atau sudah tersedia!\n");
        printf("Masukkan kata baru : ");
        STARTWORD();
    }
    if (!(currentWord.Length == 1 && currentWord.TabWord[0] == 'q')){
        InsertSetStr(&listKata, wordToString(currentWord));
        file = fopen("../data/hangman.txt", "w");
        fprintf(file, "%d\n", listKata.Count);
        for (i = 0; i < listKata.Count-1; i++)
        {
            fprintf(file, "%s\n", listKata.Elements[i]);
        }
        fprintf(file, "%s", listKata.Elements[i]);
        printf("Kata %s berhasil dimasukkan.\n", wordToString(currentWord));
        fclose(file);
    }
}

int hangman(){
    int score = -1;
    boolean exit = false;
    opening1();
    mainhangman();
    while (!exit){
        printf("\nMasukkan perintah : ");
        STARTWORD();
        if (currentWord.TabWord[0]  == '1' && currentWord.Length == 1){
            hangmanset(&score);
            exit = true;
        } else if (currentWord.TabWord[0]  == '2' && currentWord.Length == 1){
            saveKata();
        } else if (currentWord.TabWord[0]  == '3' && currentWord.Length == 1){
            keluarhangman();
            score = 0;
            exit = true;
        } else{
            printf("Masukkan tidak valid!\n");
        }
    }
    printf("Skor: %d\n", score);
    return score;
}