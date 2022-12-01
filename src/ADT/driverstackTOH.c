#include <stdio.h>
#include "stackTOH.h"

int main()
{
    Tower s;
    disk val;
    CreateEmptyTower(&s);
    printf("Mengecek apakah Tower kosong: ");
    if (IsEmptyTower(s))
    {
    printf("Tower kosong\n");
    }
    else if(!IsEmptyTower(s) && !IsFullTower(s))
    {
    printf("Tower tidak kosong dan tidak penuh\n");
    }
    else if (IsFullTower(s))
    {
    printf("Tower penuh\n");
    }
    
    printf("\nMelakukan proses memasukan elemen (2, 3, 1) secara terurut ke Tower\n");
    PushTower(&s, 2);
    PushTower(&s, 3);
    PushTower(&s, 1);
    printf("\nMelakukan proses mengeluarkan elemen dari Tower paling atas\n");
    PopTower(&s, &val);

    printf("\nBerikut adalah isi dari Tower dari paling bawah:\n");
    for (int i = 0; i < 2; i++){
        printf("%d. %d\n", i+1, s.T[i]);
    }
    return 0;
}