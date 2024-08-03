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

int findIf2ElementsSum(int *arr, int size, int value, int *iPtr, int *jPtr){
    int j = size - 1;
    int i = 0;
    while(i < j){
        int sum = arr[i] + arr[j];
        if(sum == value){
            *iPtr = i;
            *jPtr = j;
            return 1;
        }
        else if(sum > value){
            j--;
        }
        else {
            i++;
        }
    }
    return 0;
}


void printArray(int *arr, int size){
    for(int i = 0; i < size; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
int main(){
    int arr[SIZE] = {6, 1, 2, 9, 10};
    int value = 0;
    int result, firstElement, secondElement;
    bubbleSortAlgorithm(arr, SIZE);
    printArray(arr, SIZE);
    result = findIf2ElementsSum(arr, SIZE, value, &firstElement, &secondElement);
    if (result == 1){
        printf("there is a couple of elements equals to the defined value at %d and %d\n", firstElement, secondElement);
    }
    else {
        printf("There is no couple\n");
    }
}