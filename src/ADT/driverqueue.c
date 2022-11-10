#include "queue.h"
#include <stdio.h>

int main(){
    Queue Q;
    ElType var; // elemen adalah array of character
    CreateQueue(&Q); //membuat queue kosong
    printf("Elemen Queue adalah sebuah array of character\n");
    printf("\nMenambahkan elemen ke queue\n");
    printf("Isi queue pertama kali : \n");
    displayQueue(Q);
    printf("Isi queue setelah penambahan elemen : \n");
    enqueue(&Q, "Elemen Pertama"); //menambahkan elemen ke queue
    enqueue(&Q, "Elemen Kedua"); //menambahkan elemen kedua ke queue dan melihat posisi penambahan elemen
    displayQueue(Q);
    printf("\nMengecek apakah queue kosong, queue penuh, atau tidak keduanya :\n");
    if (isEmpty(Q)) //mengecek apakah queue kosong
    {
        printf("Queue kosong\n");
    }
    else if (isFull(Q)) //mengecek apakah queue penuh
    {
        printf("Queue penuh\n");
    }
    else
    {
        printf("Queue tidak kosong dan tidak penuh\n");
    }
    printf("\nMenampilkan panjang dari queue : %d\n", length(Q)); //menampilkan panjang dari queue
    displayQueue(Q); //menampilkan isi queue
    printf("\nMenghapus elemen dari queue\n");
    dequeue(&Q, &var); //menghapus elemen dari queue
    displayQueue(Q); //menampilkan isi queue apakah terhapus atau tidak dan meihat posisi penghapusan elemen

    return 0;
}