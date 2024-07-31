#include <stdio.h>
#include <stdlib.h>

#define SIZE 5
//iterative approach
int sortedFunction(int *arr, int size, int *pass){
    *pass = 1; //assuming that the array is really sorted
    for(int i = 1; i < size; i++){
        if(arr[i] <= arr[i-1]){
            *pass = 0; //the arry is not really sorted
        }
        if(arr[i] < arr[i-1]){
            return 0; //the array is not sorted
        }
    }
    return 1;
}

//Recursion approach
//Recursive alls with some logic behind them
//Base/Stopping condition

int checkIsSortedRecursion(int *arr, int size, int *pass){
    int returnValue;
    if(size == 1){
        *pass = 1; //assume that the array is really sorted
        return 1;
    }
    returnValue = checkIsSortedRecursion(arr, size - 1, pass);
    if(returnValue != 0 && arr[size-1] == arr[size-2]){
        *pass = 0;
    }
    if(returnValue != 0 && arr[size-1] < arr[size-2]){
        *pass = 0;
        return 0;
    }
    return returnValue;
}

int main(){
    int array1[SIZE] = {1, 2, 5, 7, 10}; //result = 1, pass = 1 => really sorted
    int array2[SIZE] = {1, 2, 2, 5, 10}; //result = 1, pass = 0 => sorted
    int array3[SIZE] = {1, 2, 5, 3, 10}; //result = 0, pass = 0 => not sorted
    int pass1, pass2, pass3, pass4, pass5, pass6; //pass is used to check whether one array is sorted or really sorted
    int result1 = sortedFunction(array1, SIZE, &pass1);//result is used to check one array is sorted or not sorted
    int result2 = sortedFunction(array2, SIZE, &pass2);
    int result3 = sortedFunction(array3, SIZE, &pass3);
    
    int result4 = checkIsSortedRecursion(array1, SIZE, &pass4);
    int result5 = checkIsSortedRecursion(array2, SIZE, &pass5);
    int result6 = checkIsSortedRecursion(array3, SIZE, &pass6);

    printf("result1: %d, pass1 = %d \n", result1, pass1);
    printf("result2: %d, pass2 = %d \n", result2, pass2);
    printf("result3: %d, pass3 = %d \n", result3, pass3);

    printf("result4: %d, pass4 = %d \n", result4, pass4);
    printf("result5: %d, pass5 = %d \n", result5, pass5);
    printf("result6: %d, pass6 = %d \n", result6, pass6);

}