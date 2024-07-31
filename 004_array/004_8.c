#include<stdio.h>
#define SIZE 4
//017 challenge 6
//Write a function that receives an array of characters and reverse it

void swap(char *ptr1, char *ptr2){
    char temp;
    temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

void printArray(char *arr, int size){
    for(int i = 0; i < size; i++){
        printf("%c", arr[i]);
    }
    printf("\n");
}

void reverseArrIterative(char* arr, int size){
    for(int i = 0; i < size/2; i++){
        swap(&arr[i], &arr[size-1-i]);
    }
}

void reverseRecursion(char* arr, int size){
    if(size > 1){
        swap(&arr[0], &arr[size-1]);
        reverseRecursion(arr+1, size - 2);
    }
}

int main(){
    char arr[SIZE] = {'a', 'b', 'c', 'd'};
    char arr2[SIZE] = {'1', '2', '3', '4'};
    printArray(arr, SIZE);
    reverseArrIterative(arr, SIZE);
    printArray(arr, SIZE);

    printArray(arr2, SIZE);
    reverseRecursion(arr2, SIZE);
    printArray(arr2, SIZE);
}