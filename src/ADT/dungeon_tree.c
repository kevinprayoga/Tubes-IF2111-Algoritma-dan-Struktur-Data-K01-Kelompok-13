#include <stdio.h>
#include <stdlib.h>
#include "dungeon_tree.h"

Tree NewTree(ElType root, Tree left, Tree mid, Tree right){
    Tree p = newNode(root);
    Left(p) = left;
    Mid(p) = mid;
    Right(p) = right;
    return p;
}

Address newNode(ElType x){
    Address p = (Node *)malloc(sizeof(Node));
    if(p != Nil){
        Info(p) = x;
        Left(p) = Nil;
        Mid(p) = Nil;
        Right(p) = Nil;
    }
    return p;
}

void deleteNode(Address p){
    free(p);
}

boolean isTreeEmpty(Tree p){
    return(p == Nil);
}

boolean isOneElmt(Tree p){
    return(isNoneLeft(p) && isNoneMid(p) && isNoneRight(p));
}

boolean isNoneLeft(Tree p){
    return(Left(p) == Nil);
}

boolean isNoneMid(Tree p){
    return(Mid(p) == Nil);
}

boolean isNoneRight(Tree p){
    return(Right(p) == Nil);
}

boolean isTerner(Tree p){
    return(!isOneElmt(p));
}

int nbElmt(Tree p){
    if(isTreeEmpty(p)){
        return 0;
    }
    else{
        if(isOneElmt(p)){
            return 1;
        }
        else{
            switch(p){
                case isTerner(p):
                    return 1 + nbElmt(Left(p)) + nbElmt(Mid(p)) + nbElmt(Right(p));
                case isNoneLeft(p) && isNoneMid(p):
                    return 1 + nbElmt(Right(p));
                case isNoneLeft(p) && isNoneRight(p):
                    return 1 + nbElmt(Mid(p));
                case isNoneMid(p) && isNoneRight(p):
                    return 1 + nbElmt(Left(p));
                case isNoneLeft(p):
                    return 1 + nbElmt(Mid(p)) + nbElmt(Right(p));
                case isNoneMid(p):
                    return 1 + nbElmt(Left(p)) + nbElmt(Right(p));
                case isNoneRight(p):
                    return 1 + nbElmt(Left(p)) + nbElmt(Mid(p));
            }
        }
    }
}

void insertNode(Tree *p, ElType n){
    
}

void deleteNode(Tree *p, ElType n);