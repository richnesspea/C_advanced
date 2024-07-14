#include <stdio.h>
#include <stdlib.h> //used for memcpy
#include <string.h>
//void swapInt(int *a, int *b){}
//void swapInt(double *a, double *b){}


//Dont need multiple functions
void genericSwap(void *a, void *b, int size){ //we assume that size ?> 0
    //size specfies the number of bytes
    void *tempMemory = malloc(size);
    //memory copy Function: void *memcpy(void *dest, const void *src, size_t num)
    memcpy(tempMemory, a, size); //copy data from A to temp
    memcpy(a, b, size); //copy data from B to A
    memcpy(b, tempMemory, size); //copy data from Temp to B
    free(tempMemory);
}

int main(){
    int num1 = 5, num2 = 7;
    double average1 = 8.7, average2 = 9.2;
    genericSwap(&num1, &num2, sizeof(int));
    genericSwap(&average1, &average2, sizeof(double));
    printf("num1 = %d \n", num1);
    printf("num2 = %d \n", num2);
    printf("avr1 = %f \n", average1);
    printf("avr2 = %f \n", average2);
}