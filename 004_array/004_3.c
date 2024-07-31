#include <stdio.h>

#define SIZE 4

void inputArray(int *arr, int size){
    for(int i = 0; i < size; i++){
        printf("Enter the value at %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
}

void displayArray(int *arr, int size){
    for(int i = 0; i < size; i++){
        printf("Values at %d = %d\n", i + 1, arr[i]);
    }
}

int main(){
    int grades[SIZE];
    inputArray(grades, SIZE);
    displayArray(grades, SIZE);
}