#include <stdio.h>
#define SIZE 5
//Write a function that receives a sorted (smallest-> largest) array of elements.
//The function also receives a value and check if there is a sum of 2 elements in the array that equals to received value.
//if yes return 1 and pass indexes, if no return 0

int sum2Elements(int *arr, int size, int sum, int *iPtr, int *jPtr){
    for(int i = 0; i < size; i++){
        for(int j = i + 1; j < size; j++){
            if (arr[i] + arr[j] == sum){
                *jPtr = j;
                *iPtr = i;
                return 1;
            }
        }
    }
    *jPtr = 0;
    *iPtr = 0;
    return 0;
}



int main(){
    int arr[SIZE] = {1, 2, 3, 4, 5};
    int index1, index2;
    int sum = 10;
    int result;
    result = sum2Elements(arr, SIZE, sum, &index1, &index2); 
    printf("result = %d, index1 = %d, index2 = %d\n", result, index1, index2);
}