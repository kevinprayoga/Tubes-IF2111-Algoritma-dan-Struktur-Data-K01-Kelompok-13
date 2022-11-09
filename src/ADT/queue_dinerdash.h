#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mesinkata.h"

#ifndef QUEUE_DINER_DASH_
#define QUEUE_DINER_DASH_

#define boolean unsigned char
#define true 1
#define false 0

#define IDX_UNDEF -1
#define CAPACITY 100

/* Definisi elemen dan address */
typedef struct{
    int id;
    int time;
    int expired;
    int price;
} Food;
typedef struct {
	Food buffer[CAPACITY]; 
	int idxHead;
	int idxTail;
} QueueFood;

typedef struct{
    int id;
    int cookLeft;
    int serveLeft;
} Cook;
typedef struct {
	Cook buffer[CAPACITY]; 
	int idxHead;
	int idxTail;
} QueueCook;
/* ********* AKSES (Selektor) ********* */
/* Jika q adalah Queue, maka akses elemen : */
#define IDX_HEAD(q) (q).idxHead
#define IDX_TAIL(q) (q).idxTail
#define     HEAD(q) (q).buffer[(q).idxHead]
#define     TAIL(q) (q).buffer[(q).idxTail]

void CreateQueueFood(QueueFood *q);

void CreateQueueCook(QueueCook *q);

/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah q kosong */

/* ********* Prototype ********* */
boolean isEmptyFood(QueueFood q);

boolean isEmptyCook(QueueCook q);

/* Mengirim true jika q kosong: lihat definisi di atas */
int lengthFood(QueueFood q);

int lengthCook(QueueCook q);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */

/* *** Primitif Add/Delete *** */
void enqueueFood(QueueFood *q, Food val);
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur" dalam buffer melingkar. */

void dequeueFood(QueueFood *q);
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. q tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd I.S., IDX_HEAD "mundur";
        q mungkin kosong */

void enqueueCook(QueueCook *q, Cook val);
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur" dalam buffer melingkar. */

void dequeueCook(QueueCook *q);
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. q tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd I.S., IDX_HEAD "mundur";
        q mungkin kosong */

#endif