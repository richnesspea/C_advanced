#include <stdio.h>
#include <stdlib.h>// used for malloc function
/*
    Pointers Motivation
        1. Passing py pointer
        2. Returning more than just one thing from a function
        3. Passing arrays and strings to functions
        4. Allocating unkknown memory at "run time"
    Functions to allocatte memory
        1. Malloc:
            * Allocate a "sequencec of bytes". For example, we need memory for 3 integer variables -> 12 bytes
            * Return the ADDRESS of the sequence: the address of the FIRST BYTE, for example: 3000
            * Not always succeed in allocating  (maybe OS doesn't have enough memory resource)
        2. Calloc
*/

int main(){
    int *a;
    int arraySize;
    //scanf("%d", &arraySize);
    arraySize = 3;
    a = (int *)malloc(sizeof(int) * arraySize);
    //malloc function returns the ADDRESS of the sequence (like a array)
    //sizeof(int) = 4: as one integer var needs 4 bytes to store
    //(int *): because malloc function returns a void star, so we need to specify how we treat pointer a. In this case, a will point to an array of integers.
    //a will be a pointer which points to the first address of the sequence

    double *b;
    int arraySize2;
    arraySize2 = 2;
    b = (double *)malloc(sizeof(double) * arraySize2);
    if(b != NULL){
        printf("Allocation succedded\n");
    }
    else{
        printf("Allocation failed");
    }

}