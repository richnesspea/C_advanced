#include <stdio.h>
#define SIZE 5

//Bubble sort algorithm
//2 1 3 5 4 
//1 2 3 5 4
//1 2 3 5 4
//1 2 3 4 5
void bubbleSortAlgorithm(int *arr, int size){
    for (int i = 0; i < size - 1; i++){
        for (int j = 0; j < size - 1; j++){
            if(arr[j] > arr[j+1]){
            int temp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp;
            }
        }
    }
}
void printArray(int *arr, int size){
    for(int i = 0; i < size; i++){
        printf("%d ",arr[i]);
    }
}
int main(){
    int arr[SIZE] = {6, 1, 2, 9, 10};
    bubbleSortAlgorithm(arr, SIZE);
    printArray(arr, SIZE);
}