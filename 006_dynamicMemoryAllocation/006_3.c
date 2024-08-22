#include <stdio.h>
#include <stdlib.h>

int* createArray(int size){
    int* array = (int*)malloc(size * sizeof(int));
    //check if memory allocation was successfull
    if(array == NULL){
        printf("Memory allocation failed\n");
        exit(1);
    }
    return array; //Return the pointer to the first element of the array
}

//Function to fill the array with the sequential numbers
void fillArray(int *array, int size){
    for(int i = 0; i < size; i++){
        array[i] = i + 1;
    }
}

//Function to print the array
void printArray(int *array, int size){
    for(int i = 0; i < size; i++){
        printf("%d \n", array[i]);
    }
}

int main(){
    int size = 4;
    int* myArray = createArray(size);
    //fill the array
    fillArray(myArray, size);
    printArray(myArray, size);
    free(myArray);
    return 0;
}