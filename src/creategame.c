#include "creategame.h"

int customGame(){
    srand(time(0));
    printf("Skor akhir Anda = %d\n", rand()%100);
}

char* strconcat(char* str1, char* str2){
    int i = 0;
    int j = 0;
    int len1 = stringLength(str1);
    int len2 = stringLength(str2);
    char* ans = (char*) malloc((len1+len2+1)*sizeof(char));
    while (i < len1){
        ans[i] = str1[i];
        i++;
    }
    while (j < len2){
        ans[i] = str2[j];
        i++;
        j++;
    }
    ans[i] = '\0';
    return ans;
}

Word concatword(Word word1, Word word2){
    Word word;
    int i = 0;
    int j = 0;
    while (i < word1.Length){
        word.TabWord[i] = word1.TabWord[i];
        i++;
    }

    while (j < word2.Length){
        word.TabWord[i] = word2.TabWord[j];
        i++;
        j++;
    }
    word.Length = i;
    return word;
}

void createGame(ArrayDin* list_game){
    printf("Masukkan nama game yang akan ditambahkan: ");
    STARTWORD();
    boolean found;
    found = false;
    int j = 0;
    char* cc;
    char* cc2;
    cc2 = WordToStr(currentWord);
    while(!(EndWord)){
        ADVWORD();
        cc2 = strconcat(cc2, WordToStr(currentWord));
    }
    
    if (!(IsEmpty(*list_game))){
        while (j < Length(*list_game) && found){
            cc = (*list_game).A[j];
            printf("testing\n");
            if ((strcompare(cc2, cc))){
                found = true;
            }
        j++;
        }
    }
    if (found == true){
        printf("Game sudah tersedia.\n");
    } else{
        InsertLast(list_game, WordToStr(currentWord));
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

