#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "dungeon_tree.h"

/* Menghasilkan sebuah pohon dari root, left, mid, dan right, jika alokasi berhasil 
   Menghasilkan pohon kosong (Nil) jika alokasi gagal */
Tree createTree(ElType root, Tree left, Tree mid, Tree right, int level, int diff){
    srand(time(0));

    Tree p = (Address) malloc (sizeof(Tree));
    if(p != Nil){
        int i = 0;
        if(i != level){
            i++;
            Info(p) = root;
            if(rand()%100 < diff){
                Left(p) = createTree(root, Left(left), Mid(left), Right(left), i);
            }
            if(rand()%100 < diff){
                Mid(p) = createTree(root, Left(mid), Mid(mid), Right(mid), i);
            }
            if(rand()%100 < diff){
                Right(p) = createTree(root, Left(right), Mid(right), Right(right), i);
            }
        }
    }
    return p;
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
  if(p != Nil){
    destroyTree(Left(p));
    destroyTree(Mid(p));
    destroyTree(Right(p));
    delNode(p);
  }
}

/* I.S. p terdefinisi 
   F.S. p dikembalikan ke sistem 
   Melakukan dealokasi/pengembalian address p */
void delNode(Address p){
    free(p);
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

/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
addr alloc(Address x){
    addr p = (addr) malloc (sizeof(InfoList));
    if (p != Nil){
        Elmt(p) = x;
        Next(p) = Nil;
    }
    return p;
}

/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
void dealloc(addr *p){
    free(*p);
}

/* Mengirim true jika list kosong */
boolean isEmptyList(ListOfNode l){
    return(First(l) == Nil && Last(l) == Nil);
}

/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
void insFirst(ListOfNode *l, Address x){
    addr p = alloc(x);
    if(p != Nil){
        if(isEmptyList(*l)){
            Last(*l) = p;
        }
        Next(p) = First(*l);
        First(*l) = p;
    }
}

/* Mengirimkan salinan hasil konkatenasi list L1 dan L2 (menjadi list baru)
   Jika ada alokasi gagal, menghasilkan Nil */
ListOfNode concat(ListOfNode L1, ListOfNode L2, ListOfNode L3){
	switch(L1, L2, L3)
		case L1 == Nil && L2 == Nil && L3 == Nil:
            return Nil;
        case L2 == Nil && L3 == Nil:
            return L1;
        case L1 == Nil && L3 == Nil:
            return L2;
        case L1 == Nil && L2 == Nil:
            return L3;
        case L1 == Nil:
            ListOfNode L;
            First(L) = First(L2);
            Last(L) = Last(L2);
            Next(Last(L)) = First(L3);
            Last(L) = Last(L3);
            return L;
        case L2 == Nil:
            ListOfNode L;
            First(L) = First(L1);
            Last(L) = Last(L1);
            Next(Last(L)) = First(L3);
            Last(L) = Last(L3);
            return L;
        case L3 == Nil:
            ListOfNode L;
            First(L) = First(L1);
            Last(L) = Last(L1);
            Next(Last(L)) = First(L2);
            Last(L) = Last(L2);
            return L;
        default:
            ListOfNode L;
            First(L) = First(L1);
            Last(L) = Last(L1);
            Next(Last(L)) = First(L2);
            Last(L) = Last(L2);
            Next(Last(L)) = First(L3);
            Last(L) = Last(L3);
            return L;
}

/* Jika p adalah pohon kosong, maka menghasilkan list kosong.
   Jika p bukan pohon kosong: menghasilkan list yang elemennya adalah semua elemen
   pohon p yang levelnya=n, jika semua alokasi berhasil. Menghasilkan list kosong jika ada alokasi yang gagal. */
void makeListLevel(ListOfNode *L, Tree p, int n){
	if(isTreeEmpty(p)){
		*L = Nil;
	}
	else{
		if(n==0){
			*L = insFirst(L, p);
		}
		else{
			*L = concat(makeListLevel(L, Left(p), n-1), makeListLevel(L, Mid(p), n-1), makeListLevel(L, Right(p), n-1));
		}
	}
}

void delList(ListOfNode L){
    addr p;
    while(!isEmptyList(L)){
        p = First(L);
        if(First(L) == Last(L)){
            Last(L) = Nil;
        }
        First(L) = Next(p);
        dealloc(p);
    }
}