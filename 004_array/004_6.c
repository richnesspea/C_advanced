#include <stdio.h>

#define SIZE 5

int hasNeighbors(int arr[], int size){
    for(int i = 0; i < size - 1; i++){
        if(arr[i+1] == (arr[i]+arr[i+2])){
            return 1;
        }
    }
    return 0;
}

int main(){
    int array1[SIZE] = {1, 4, 7, 3, 2};
    int array2[SIZE] = {1, 4, 1, 4, 2};
    int result1, result2;
    result1 = hasNeighbors(array1, SIZE);
    result2 = hasNeighbors(array2, SIZE);
    printf("array1, result: %d \n", result1);
    printf("array2, result: %d \n", result2);
    }