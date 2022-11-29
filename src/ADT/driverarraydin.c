#include <stdio.h>
#include "arraydin.h"

int main()
{
    ArrayDin arr;
    arr = MakeArrayDin();
    printf("Capacity of array: %d\n", GetCapacity(arr));
    if (IsEmpty(arr))
    {
        printf("Array is empty\n");
    }
    else
    {
        printf("Array is not empty\n");
    }
    
    printf("\nInserting 'First' at index 0\n");
    InsertAt(&arr, "FIrst", 0);
    PrintArrayDin(arr);

    printf("\nLength of array: %d\n", Length(arr));
    
    printf("\nInserting 'Second' at first index\n");
    InsertFirst(&arr, "Second");
    PrintArrayDin(arr);

    printf("\nInserting 'Third' at last index\n");
    InsertLast(&arr, "Third");
    PrintArrayDin(arr);

    printf("\nGet element at index 1: %s\n", Get(arr, 1));

    printf("\nDelete element at first index\n");
    DeleteFirst(&arr);
    PrintArrayDin(arr);

    printf("\nDelete element at index 0\n");
    DeleteAt(&arr, 0);

    printf("\nDelete element at last index\n");
    DeleteLast(&arr);
    PrintArrayDin(arr);

    printf("\nDeallocate array\n");    
    DeallocateArrayDin(&arr);

    printf("\nGet number of element from array\n");
    GetNum(arr, "Second");
    return 0;
}