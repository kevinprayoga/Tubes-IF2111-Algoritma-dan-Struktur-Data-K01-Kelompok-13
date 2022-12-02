#ifndef __DUNGEON_TREE__
#define __DUNGEON_TREE__

#include "../boolean.h"

#define Nil NULL

/* selektor */
#define Info(p) (p)->info
#define Left(p) (p)->left
#define Mid(p) (p)->mid
#define Right(p) (p)->right

#define Elmt(l) (l)->elmt
#define Next(l) (l)->next
#define First(l) (l)->first
#define Last(l) (l)->last

typedef int ElType;

typedef struct node* Address;
typedef struct node{
    ElType info;
    Address left;
    Address mid;
    Address right;
} Node;
typedef Address Tree;

typedef struct infoList* addr;
typedef struct infoList{ 
	Address elmt;
	addr next;
} InfoList;
typedef struct{
	addr first;
    addr last;
} ListOfNode;

/*
 * Konstruktor
 * Fungsi pembangun tree dari akar, left tree, middle tree, dan right tree.
 * Jika alokasi gagal, maka dihasilkan pohon kosong (Nil)
 */
Tree createTree(ElType root, Tree left, Tree mid, Tree right, int level, int diff);

/* 
 * Alokasi
 * I.S. sembarang 
 * F.S. Menghasilkan address hasil alokasi elemen x
 * Jika alokasi berhasil, maka info berisi x, left, mid, dan right berisi Nil
 * Jika gagal, mengirimkan Nil 
 */
Address newNode(ElType x);

/*
 * Destruktor
 * I.S. Tree terdefinisi
 * F.S. Tree terdealokasi
 */
void destroyTree(Tree p);

/*
 * Dealokasi
 * I.S. Node terdefinisi
 * F.S. Node terdealokasi
 */
void delNode(Address *p);

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
 * Fungsi untuk mengembalikan jumlah elemen tree
 * Prekondisi: tree terdefinisi
 */
int NbElmt(Tree p);

/*
 * Fungsi untuk mengembalikan level dari node x yang merupakan salah satu simpul dari pohon p
 * Prekondisi: tree terdefinisi
 */
int Level(Tree p, ElType x);

/*
 * Fungsi untuk mengembalikan true apabila elemen x merupakan salah satu info dari node pohon p
 *              mengembalikan false apabila tidak ditemukan
 * Prekondisi: tree terdefinisi
 */
boolean Search(Tree p, ElType x);

/*
 * Fungsi untuk menampilkan indentasi sesuai dengan level tree
 * Prekondisi: tree terdefinisi
 */
void printSpace(int h);

/*
 * Fungsi untuk menampilkan tree dengan indentasi sesuai dengan level tree
 * Prekondisi: tree terdefinisi
 */
void printLevelTree(Tree p, int h, int lvl);

/*
 * Fungsi untuk menampilkan tree secara keseluruhan
 * Prekondisi: tree terdefinisi
 */
void printTree(Tree p);

/*
 * Fungsi untuk mengalokasikan address list seukuran list of node
 */
addr alloc(Address x);

/*
 * Prosedur membebaskan address list dan dikembalikan ke sistem
 * Prekondisi: address list terdefinisi
 */
void dealloc(addr *p);

/*
 * Fungsi untuk mengembalikan true apabila list of node kosong
 * Prekondisi: list terdefinisi
 */
boolean isEmptyList(ListOfNode l);

/*
 * Fungsi untuk memasukkan address ke awal list
 * Prekondisi: list dan address terdefinisi
 */
void insFirst(ListOfNode *l, Address x);

/*
 * Fungsi untuk mengkonkatenasi 3 list of node
 * Prekondisi: ketiga list terdefinisi
 */
ListOfNode concat(ListOfNode L1, ListOfNode L2, ListOfNode L3);

/*
 * Fungsi untuk membuat list dari sebuah level tree
 * Prekondisi: tree terdefinisi
 */
void makeListLevel(ListOfNode *L, Tree p, int n);

/*
 * Prosedur untuk menhapus list
 * Prekondisi: List terdefinisi
 */
void delList(ListOfNode L);

#endif