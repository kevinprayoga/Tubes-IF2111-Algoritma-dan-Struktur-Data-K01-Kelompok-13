#include <stdio.h>
#include <stdlib.h>
#include "dungeon_tree.h"

/* Menghasilkan sebuah pohon dari root, left, mid, dan right, jika alokasi berhasil 
   Menghasilkan pohon kosong (Nil) jika alokasi gagal */
void createTree(Tree *p, ElType root, Tree left, Tree mid, Tree right){
    *p = (Address) malloc (sizeof(Tree));
    if(*p != Nil){
        Info(*p) = root;
        Left(*p) = left;
        Mid(*p) = mid;
        Right(*p) = right;
    }
}

/* Alokasi sebuah address p, bernilai tidak Nil jika berhasil */
/* Mengirimkan address hasil alokasi sebuah elemen bernilai val
   Jika alokasi berhasil, maka address tidak Nil, dan misalnya 
   menghasilkan p, maka p↑.info=x, p↑.left=Nil, p↑.mid=Nil, p↑.right=Nil 
   Jika alokasi gagal, mengirimkan Nil */
Address newNode(ElType x){
    Address p = (Address) malloc (sizeof(Node));
    if(p != Nil){
        Info(p) = x;
        Left(p) = Nil;
        Mid(p) = Nil;
        Right(p) = Nil;
    }
    return p;
}

/* I.S. tree terdefinisi 
   F.S. tree dikembalikan ke sistem 
   Melakukan dealokasi/pengembalian tree p */
void destroyTree(Tree p){
  delNode(&p);
  free(p);
}

/* I.S. p terdefinisi 
   F.S. p dikembalikan ke sistem 
   Melakukan dealokasi/pengembalian address p */
void delNode(Address *p){
  if(*p != Nil){
    delNode(Left(*p));
    delNode(Mid(*p));
    delNode(Right(*p));
    free(*p);
  }
}

/* Mengirimkan true jika p adalah pohon yang kosong */
boolean isTreeEmpty(Tree p){
    return(p == Nil);
}

/* Mengirimkan true jika p tidak kosong dan hanya terdiri atas 1 elemen */
boolean isOneElmt(Tree p){
    return(isNoneLeft(p) && isNoneMid(p) && isNoneRight(p));
}

/* Mengirimkan true jika pohon kosong atau p adalah pohon yang 
   tidak mempunyai subpohon kiri */
boolean isNoneLeft(Tree p){
    return(Left(p) == Nil);
}

/* Mengirimkan true jika pohon kosong atau p adalah pohon yang 
   tidak mempunyai subpohon tengah */
boolean isNoneMid(Tree p){
    return(Mid(p) == Nil);
}

/* Mengirimkan true jika pohon kosong atau p adalah pohon yang 
   tidak mempunyai subpohon kanan */
boolean isNoneRight(Tree p){
    return(Right(p) == Nil);
}

/* Mengirimkan true jika pohon tidak kosong, p adalah pohon yang 
   mempunyai subpohon kiri, tengah, kanan */
boolean isTerner(Tree p){
    return(!isOneElmt(p));
}

/* Mengirimkan banyaknya elemen (node) pohon terner p */
int NbElmt(Tree p){
	if(isTreeEmpty(p)){
		return 0;
	}
	else{
		return 1+NbElmt(Left(p))+NbElmt(Mid(p))+NbElmt(Right(p));
	}
}

/* Mengirimkan level dari node x yang merupakan salah satu simpul dari pohon p
   Info(p) levelnya 1. Pohon p tidak kosong. */
int Level(Tree p, ElType x){
	if(x==Info(p)){
		return 1;
	}
	else
        switch(p, x)
            case Search(Left(p), x):
                return 1+Level(Left(p), x);
            case Search(Mid(p), x):
                return 1+Level(Mid(p), x);
            case Search(Right(p), x):
                return 1+Level(Right(p), x);
}

/* Mengirimkan true jika ada node dari p yang bernilai x */
boolean Search(Tree p, ElType x){
	if(isTreeEmpty(p)){
		return false;
	}
	else if(x==Info(p)){
		return true;
	}
	else{
		return(Search(Left(p), x) || Search(Mid(p), x) || Search(Right(p), x));
	}
}

/* Menampilkan indentasi sesuai dengan level tree */
void printSpace(int h){
    for(int i = 0; i < h; i++){
        printf(" ");
    }
}

/* Menampilkan tree dengan indentasi sesuai dengan level tree */
void printLevelTree(Tree p, int h, int lvl){
    if(isTreeEmpty(p)){
        printf("");
    }
    else if(isOneElmt(p)){
        printSpace(h * lvl);
        printf("%d\n", Info(p));
    } 
    else{
        printSpace(h * lvl);
        printf("%d\n", Info(p));
        printLevelTree(Left(p), h, lvl + 1);
        printLevelTree(Mid(p), h, lvl + 1);
        printLevelTree(Right(p), h, lvl + 1);
    }
} 

/* Menampilkan tree dari level tertentu */
void printTree(Tree p){
    printLevelTree(p, 2, 0);
}