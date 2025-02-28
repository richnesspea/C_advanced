#include <stdio.h>

#define SIZE 6
//Develop a recursive function that receives an array of integers and its size
//Return 1: 2 adjacent elements have the opposite sign
//Return 0: otherwise

int exchangingSign(int *arr, int size){
    
    //Stop condition
    if(size <= 2){
        return 1;
    }
    int product = arr[size-1]*arr[size-2];
    

    if(product < 0){
        exchangingSign(arr, size-1);
    }
    else{
        return 0;
    }

}

int main(){
    int arr[SIZE] = {1, -2, -3, -4, 5, -6}; 
    int result;
    result = exchangingSign(arr, SIZE);
    printf("exchanging signs array result is: %d \n", result);
}