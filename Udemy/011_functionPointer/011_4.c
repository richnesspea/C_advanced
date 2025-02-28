// Using function pointers with void pointers in C

#include <stdio.h>

// Function to print an integer
void printInt(void *a){
    printf("%d", *(int*)a);
}

// Function to print an float
void printFloat(void *a){
    printf("%.2f", *(float*)a);
}

// Function to perform an operation on all elements of an array
void performOperation(void *arr, int arrLength, int elementSize, void (*operation)(void *)){
    //First argument: a void pointer that points to the start address of array
    //Second argmuent: the number of elements of this array
    //Third argument: the number of bytes required for each elements 
    //Actual argument: the operation
    for (int i = 0; i < arrLength; i++){
        operation((char*)arr + i*elementSize); //Truy cập từng thành phần của mảng
        printf("\n");
    }
}
int main(){
    //Integer array
    int arrInt[] = {1, 2, 3};
    performOperation(arrInt, sizeof(arrInt)/sizeof(arrInt[0]), sizeof(int), printInt);
    //Float array
    float arrFloat[] = {1.1, 1.2, 1.3};
    performOperation(arrFloat, sizeof(arrFloat)/sizeof(arrFloat[0]), sizeof(float), printFloat);
}