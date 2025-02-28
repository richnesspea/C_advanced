#ifndef __1_HEADER_H__
#define __1_HEADER_H__
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100


typedef struct {
    int*address; //Pass by pointer
    int capacity;
    int size;
} Array;

void InitArray(Array *arr, int capacity);
bool AddElement(Array *arr, int value);
bool DelElement(Array *arr, int index);
void Sort(Array *arr);
bool Search(Array *arr, int value);

void PrintArray(Array *arr);
void freeArray(Array *arr);

#endif

