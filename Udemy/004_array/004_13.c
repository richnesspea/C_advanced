#include <stdio.h>

#define SIZE 5
//Create a recursive function that receives an array of integers and its size.
//The function should return 1 if the array is a Palindrome, otherwise 0


// 12321

int checkPalindrome(int *arr, int size){
    int i = 0;
    while(i < 2){
        if(arr[i] == arr[size - 1 - i]){
            i++;
        }
        else{
            return 0;
        }
    }
    return 1;
}

int checkPalindome_recursion(int *arr, int size){
    if(size <= 1){
        return 1;
    }
    if(arr[0] != arr[size-1]){
        return 0;
    }
    checkPalindome_recursion(arr + 1, size - 2); 
}

int main(){
    int arr[SIZE] = {1, 2, 3, 2, 1};
    int result = checkPalindome_recursion(arr, SIZE);
    printf("%d", result);
}