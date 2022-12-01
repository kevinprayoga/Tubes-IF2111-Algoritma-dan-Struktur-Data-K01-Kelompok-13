#include <stdio.h>
#include "set.h"

int main()
{
    SetChar S;
    CreateEmptySetChar(&S);
    if (IsEmptySetChar(S))
    {
        printf("This char set is empty\n");
    }
    else if (!IsEmptySetChar(S) && !IsFullSetChar(S))
    {
        printf("This char set is neither empty nor full\n");
    }
    else if (IsFullSetChar(S))
    {
        printf("This char set is full\n");
    }
    InsertSetChar(&S, 'A');
    InsertSetChar(&S, 'B');
    InsertSetChar(&S, 'D');
    InsertSetChar(&S, 'M');
    InsertSetChar(&S, 'A');
    InsertSetChar(&S, 'L');
    DeleteSetChar(&S, 'Q');
    DeleteSetChar(&S, 'D');
    if (IsMemberSetChar(S, 'B'))
    {
        printf("This char is in this char set\n");
    }
    else
    {
        printf("This char is not in this char set\n");
    } 
    SetStr Str;
    CreateEmptySetStr(&Str);
    if (IsEmptySetStr(Str))
    {
        printf("This string set is empty\n");
    }
    else if (!IsEmptySetStr(Str) && !IsFullSetStr(Str))
    {
        printf("This string set is neither empty nor full\n");
    }
    else if (IsFullSetStr(Str))
    {
        printf("This string set is full\n");
    }
    InsertSetStr(&Str, "Ayam");
    InsertSetStr(&Str, "Ikan");
    InsertSetStr(&Str, "Sapi");
    InsertSetStr(&Str, "Kerbau");
    InsertSetStr(&Str, "Kuda");
    InsertSetStr(&Str, "Belalang");
    DeleteSetStr(&Str, "Kera");
    DeleteSetStr(&Str, "Kerbau");
    if (IsMemberSetStr(Str, "Ikan"))
    {
        printf("This String is in this String set\n");
    }
    else
    {
        printf("This String is not in this String set\n");
    } 
    if (IsMemberChar("Duyung", 'u'))
    {
        printf("This letter is in this string\n");
    }
    else 
    {
        printf("This letter is not in this string\n");
    }
    char* katatest, katatest2;
    int lengthkata;
    katatest = "pillow";
    katatest2 = "pillowy";
    lengthkata = strlen(katatest);
    printf("%d\n",lengthkata);
    if (strcomp(katatest,katatest2))
    {
        printf("These words are different!!\n");
    }
    else 
    {
        printf("These words are the same!!\n");
    }
}