#ifndef __DUNGEON_TREE__
#define __DUNGEON_TREE__

#include "boolean.h"

#define Nil NULL
#define size 50
/* selektor */
#define Info(p) (p)->info
#define Left(p) (p)->left
#define Mid(p) (p)->mid
#define Right(p) (p)->right

typedef int ElType;
typedef struct node* Address;
typedef struct node{
    ElType info;
    Address left;
    Address mid;
    Address right;
} Node;
typedef Address Tree;

/*
 * Konstruktor
 * Fungsi pembangun tree dari akar, left tree, middle tree, dan right tree.
 * Jika alokasi gagal, maka dihasilkan pohon kosong (Nil)
 */
Tree NewTree(ElType root, Tree left, Tree mid, Tree right);

/* 
 * Alokasi
 * I.S. sembarang 
 * F.S. Menghasilkan address hasil alokasi elemen x
 * Jika alokasi berhasil, maka info berisi x, left, mid, dan right berisi Nil
 * Jika gagal, mengirimkan Nil 
 */
Address newNode(ElType x);

/*
 * Destruktor/Dealokasi
 * I.S. Node terdefinisi
 * F.S. Node terdealokasi
 */
void deleteNode(Address *p);

/*
 * Fungsi untuk mengetahui apakah suatu tree kosong.
 * Prekondisi: tree terdefinisi
 */
boolean isTreeEmpty(Tree p);

/*
 * Fungsi untuk mengetahui apakah suatu tree terdiri dari satu elemen.
 * Prekondisi: tree terdefinisi
 */
boolean isOneElmt(Tree p);

/*
 * Fungsi untuk mengetahui apakah suatu tree tidak terdiri dari tree kiri saja.
 * Prekondisi: tree terdefinisi
 */
boolean isNoneLeft(Tree p);

/*
 * Fungsi untuk mengetahui apakah suatu tree tidak terdiri dari tree tengah saja.
 * Prekondisi: tree terdefinisi
 */
boolean isNoneMid(Tree p);

/*
 * Fungsi untuk mengetahui apakah suatu tree tidak terdiri dari tree kanan saja.
 * Prekondisi: tree terdefinisi
 */
boolean isNoneRight(Tree p);

/*
 * Fungsi untuk mengetahui apakah suatu tree terdiri dari tree kiri, tengah, dan kanan.
 * Prekondisi: tree terdefinisi
 */
boolean isTerner(Tree p);

/*
 * Fungsi untuk mendapatkan banyaknya elemen efektif tree, 0 jika tree kosong.
 * Prekondisi: tree terdefinisi
 */
int nbElmt(Tree p);

/*
 * Fungsi untuk menambahkan tree baru di leaf dengan nilai n
 * Prekondisi: tree terdefinisi, n berada dalam range 0-999.
 */
void insertNode(Tree *p, ElType n);

/*
 * Fungsi untuk menghapus tree lama di leaf dengan nilai n
 * Prekondisi: tree terdefinisi, n berada dalam range 0-999.
 */
void deleteNode(Tree *p, ElType n);

#endif