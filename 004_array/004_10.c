#include <stdio.h>
#define SIZE 7
//Write a function that receives an array. 
//The function should find and return the "Second smallest" value in the array

int secondSmallest(int *arr, int size){
    int smallestValue = arr[0];
    int maxValue = arr[0];
    int secondSmallestValue = arr[0];
    for(int i = 1; i < size; i++){
        if(arr[i] < smallestValue){
            smallestValue = arr[i];
        }
        if(arr[i] > maxValue){
            maxValue = arr[i];
        }
    }

    printf("the smallest value is %d \n", smallestValue);
    printf("the max value is %d \n", maxValue);

    secondSmallestValue = maxValue;

    for(int j = 0; j < size; j++){
        if(arr[j] > smallestValue && arr[j] < secondSmallestValue){
            secondSmallestValue = arr[j];
        }
    }
    printf("the second smallest value is %d \n", secondSmallestValue);
    return secondSmallestValue;
}

int main(){
    int arr[SIZE] = {78, 2, 3, 4, 5, 6, 7};
    int result = secondSmallest(arr, SIZE);
    printf("%d \n",result);
}