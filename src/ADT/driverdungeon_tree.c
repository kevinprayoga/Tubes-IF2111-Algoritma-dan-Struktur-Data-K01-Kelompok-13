#include "dungeon_tree.h"
#include <stdio.h>

int main(){
    Tree P;
    ElType val = 0; // info adalah integer
    P = createTree(val, Nil, Nil, Nil, 3, 3); //membuat tree kosong
    printf("Info Tree adalah sebuah integer\n");
    destroyTree(P);
    printf("\nMenambahkan daun ke tree\n");
    printf("Isi tree pertama kali : \n");
    printTree(P);
    printf("Isi tree setelah penambahan daun : \n");
    Address loc = newNode(1); //mengalokasikan node baru
    P = createTree(val, Nil, loc, Nil, 3, 3); //menambahkan node tersebut ke tree
    printTree(P);
    printf("\nMengecek apakah tree kosong, terdiri dari 1 elemen, atau lainnya :\n");
    switch(P):
        case isTreeEmpty(P):
            printf("Tree kosong.\n");
            break;
        case isOneElmt(P):
            printf("Tree terdiri dari 1 elemen.\n");
            break;
        case isNoneLeft(P) && isNoneMid(P):
            printf("Tree hanya memiliki subpohon kanan.\n");
            break;
        case isNoneLeft(P) && isNoneRight(P):
            printf("Tree hanya memiliki subpohon tengah.\n");
            break;
        case isNoneMid(P) && isNoneRight(P):
            printf("Tree hanya memiliki subpohon kiri.\n");
            break;
        case isNoneLeft(P):
            printf("Tree hanya memiliki subpohon tengah dan kanan.\n");
            break;
        case isNoneMid(P):
            printf("Tree hanya memiliki subpohon kiri dan kanan.\n");
            break;
        case isNoneRight(P):
            printf("Tree hanya memiliki subpohon kiri dan tengah.\n");
            break;
        case isTerner(P):
            printf("Tree memiliki subpohon kiri, tengah, dan kanan.\n");
            break;

    printf("\nMenampilkan jumlah node efektif dari tree : %d\n", NbElmt(P)); //menampilkan jumlah node dari tree
    printTree(P); //menampilkan isi tree
    printf("\nMenghapus node dari tree\n");
    delNode(loc); //menghapus elemen dari queue
    printTree(P); //menampilkan isi tree yang sudah dihapus

    return 0;
}