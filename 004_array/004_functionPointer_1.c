//Sorting an array using function pointers

#include <stdio.h>
#include <stdbool.h>

//Step1: Create Comparison functions:
int ascending(int a, int b ){
    return a < b;
}

int descending(int a, int b ){
    return a > b;
}

//Step2: Sort functions
void swap(int *ptr1, int *ptr2){
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

/*
int (*compare)(int, int): This is a function pointer that allows you to pass different comparison functions to the sort function. 
The comparison function takes two integers as arguments and returns an int value
*compare là một con trỏ để gọi hàm
*/


void sort(int *arr, int size, int(*compare)(int, int)){
    for(int i = 0; i < size - 1; i++){
        for (int j = 0; j < size - 1; j++){
            if(!compare(arr[j],arr[j+1])){
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

void printArray(int *arr, int size){
    printf("Array: \n");
    for(int i = 0; i < size; i++){
        printf("%d ",arr[i]);
    }
    printf("\n========================== \n");
}

int main(){
    int arr[] = {5, 1, 3, 2, 4};
    int size = sizeof(arr)/sizeof(arr[0]);
    printArray(arr, size);
    sort(arr, size, ascending);
    printArray(arr, size);
    sort(arr, size, descending);
    printArray(arr, size);
}