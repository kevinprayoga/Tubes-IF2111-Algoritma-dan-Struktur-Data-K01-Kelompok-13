#include <stdio.h>
#include <stdlib.h>
#include "arraydin.h"

ArrayDin MakeArrayDin()
{
	ArrayDin A;
	A.A = (ElType *)malloc(sizeof(ElType) * InitialSize);
	A.Capacity = InitialSize;
	A.Neff = 0;
	return A;
}

void DeallocateArrayDin(ArrayDin *array)
{
	free((*array).A);
}

boolean IsEmpty(ArrayDin array)
{
	return array.Neff == 0;
}

int Length(ArrayDin array)
{
	return array.Neff;
}

ElType Get(ArrayDin array, IdxType i)
{
	return array.A[i];
}

int GetCapacity(ArrayDin array)
{
	return array.Capacity;
}

void InsertAt(ArrayDin *array, ElType el, IdxType i)
{
	int j;
	if (Length(*array) == GetCapacity(*array))
	{
		ElType *temp = (ElType *)malloc(sizeof(ElType) * GetCapacity(*array));
		for (j = 0; j < Length(*array); j++)
		{
			temp[j] = (*array).A[j];
		}
		DeallocateArrayDin(array);
		(*array).Capacity *= 2;
		(*array).A = (ElType *)malloc(sizeof(ElType) * GetCapacity(*array));
		for (j = 0; j < Length(*array); j++)
		{
			(*array).A[j] = temp[j];
		}
		free(temp);
	}
	for (j = Length(*array); j > i; j--)
	{
		(*array).A[j] = (*array).A[j - 1];
	}
	(*array).A[i] = el;
	(*array).Neff++;
}

void InsertLast(ArrayDin *array, ElType el)
{
	int i;
	if (Length(*array) == GetCapacity(*array))
	{
		ElType *temp = (ElType *)malloc(sizeof(ElType) * GetCapacity(*array));
		for (i = 0; i < Length(*array); i++)
		{
			temp[i] = (*array).A[i];
		}
		DeallocateArrayDin(array);
		(*array).Capacity *= 2;
		(*array).A = (ElType *)malloc(sizeof(ElType) * GetCapacity(*array));
		for (i = 0; i < Length(*array); i++)
		{
			(*array).A[i] = temp[i];
		}
		free(temp);
	}
	(*array).A[Length(*array)] = el;
	(*array).Neff++;
}

void InsertFirst(ArrayDin *array, ElType el)
{
	int i;
	if (Length(*array) == GetCapacity(*array))
	{
		ElType *temp = (ElType *)malloc(sizeof(ElType) * GetCapacity(*array));
		for (i = 0; i < Length(*array); i++)
		{
			temp[i] = (*array).A[i];
		}
		DeallocateArrayDin(array);
		(*array).Capacity *= 2;
		(*array).A = (ElType *)malloc(sizeof(ElType) * GetCapacity(*array));
		for (i = 0; i < Length(*array); i++)
		{
			(*array).A[i] = temp[i];
		}
		free(temp);
	}
	for (i = Length(*array); i > 0; i--)
	{
		(*array).A[i] = (*array).A[i - 1];
	}
	(*array).A[0] = el;
	(*array).Neff++;
}

void DeleteAt(ArrayDin *array, IdxType i)
{
	int j;
	for (j = i; j < Length(*array); j++)
	{
		(*array).A[j] = (*array).A[j + 1];
	}
	(*array).Neff--;
}

void DeleteLast(ArrayDin *array)
{
	(*array).Neff--;
}

void DeleteFirst(ArrayDin *array)
{
	int i;
	for (i = 0; i < Length(*array); i++)
	{
		(*array).A[i] = (*array).A[i + 1];
	}
	(*array).Neff--;
}

void PrintArrayDin(ArrayDin array)
{
	int i;
	printf("[");
	if (Length(array) > 0)
	{
		for (i = 0; i < Length(array); i++)
		{
			printf("%s", array.A[i]);
			if (i < Length(array) - 1)
			{
				printf(", ");
			}
		}
	}
	printf("]\n");
}

IdxType GetNum(ArrayDin array, ElType el)
{
	for (int i = 0; i < Length(array); i++)
	{
		if (array.A[i] == el)
		{
			return (i + 1);
		}
	}
}