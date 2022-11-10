#include "queue_dinerdash.h"
#include <stdio.h>

int main(){
    
    QueueFood qfood;
    QueueCook qcook;
    CreateQueueFood(&qfood);
    CreateQueueCook(&qcook);

    Food f1; //assign nilai dari variable f1
    f1.id = 1;
    f1.time = 1;
    f1.expired = 1;
    f1.price = 4000;

    Cook c1; //assign nilai dari variable c1
    c1.id = 1;
    c1.cookLeft = 2;
    c1.serveLeft = 3;

    enqueueCook(&qcook, c1); //enqueue c1 ke qcook
    enqueueFood(&qfood, f1); //enqueue f1 ke qfood
    printf("\nMenampilkan isi dari tiap element type queue food :\n");
    printf("id dari elemen pertama dari queue food : %d\n", qfood.buffer[0].id);
    printf("time dari elemen pertama dari queue food : %d\n", qfood.buffer[0].time);
    printf("expired dari elemen pertama dari queue food : %d\n", qfood.buffer[0].expired);
    printf("price dari elemen pertama dari queuue food : %d\n", qfood.buffer[0].price);

    printf("\nMenampilkan isi dari tiap element type queue cook :\n");
    printf("id dari elemen pertama dari queue cook : %d\n", qcook.buffer[0].id);
    printf("cookLeft dari elemen pertama dari queue cook : %d\n", qcook.buffer[0].cookLeft);
    printf("serveLeft dari elemen pertama dari queue cook : %d\n", qcook.buffer[0].serveLeft);

    dequeueCook(&qcook);//dequeue c1 dari qcook
    dequeueFood(&qfood);//dequeue f1 dari qfood
    
    printf("\nMengecek isi dari kedua queue setelah di dequeue :\n");
    if (isEmptyFood(qfood)){
        printf("Queue food kosong\n");
    } else {
        printf("Queue food tidak kosong\n");
    }

    if (isEmptyCook(qcook)){
        printf("Queue cook kosong\n");
    } else {
        printf("Queue cook tidak kosong\n");
    }

    return 0;
    
}
