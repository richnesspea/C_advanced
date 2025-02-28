#include <stdio.h>
#define SIZE 7

//Write a function that receives an array. The function should count and print the frequency of each of the array's elements

void printValuesFrequency(int *arr, int size){
    int leftFlag; //indicates one value has appeared
    int countValue;
    for(int i = 0; i < size; i++){
        leftFlag = 0;
        countValue = 1;
        // Left Part ..
        for(int j = 0; j < i; j++){
            if (arr[j] == arr[i]){
                leftFlag = 1;
                break;
            }
        }
        if(leftFlag == 1){
            continue; //new iteration with new i, when leftFlag == 1, the rest code will be skipped
        }

        // Right Part ..
        for(int j = i+1; j < size; j++){
            if(arr[j] == arr[i]){
                countValue++;
            }
        }

        // Print the actual frequency
        // Value at arrr[i] appears countValue times
        printf("Value at %d appears %d times\n", arr[i], countValue);
    }
}

int main(){
    int arr[SIZE] = {1, 2, 3, 4, 3, 2, 1};
    printValuesFrequency(arr, SIZE);
}