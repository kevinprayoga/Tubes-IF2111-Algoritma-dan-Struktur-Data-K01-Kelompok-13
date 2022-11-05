#include "creategame.h"

int customGame(){
    srand(time(0));
    printf("Skor akhir Anda = %d\n", rand()%100);
}

void createGame(ArrayDin* List){
    printf("Masukkan nama game yang akan ditambahkan: ");
    STARTWORD();
    boolean found;
    found = false;
    int j = 0;
    char* cc;
    if (!(IsEmpty(*List))){
        while (j < 0 && found){
            cc = (*List).A[j];
            if ((strcompare(WordToStr(currentWord), cc))){
                found = true;
            }
        j++;
        }
    }
    if (found == true){
        printf("Game sudah tersedia.\n");
    } else{
        InsertLast(List, WordToStr(currentWord));
        printf("Game berhasil ditambahkan\n");
    }
}

char *WordToStr(Word kata){
    char *str = (char *)malloc((kata.Length) * sizeof(char));
    int j  = 0;
    for (int i = 0; i < kata.Length; i++)
    {
        str[i] = kata.TabWord[i];
        j++;
    }
    str[j] = '\0';
    return str;
}

int stringLength(char *str){
    int i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return i;
}

boolean strcompare(char *str1, char *str2){
    int i = 0;
    boolean found = false;
    if (stringLength(str1) != stringLength(str2)){
        return found;
    }
    else{
        while (!found && i < stringLength(str1)){
            if (str1[i] != str2[i]){
                return found;
            }
            i += 1;
        }
        return !found;
    }
}

