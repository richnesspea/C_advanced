#include <stdio.h>

int main(){
    int arr[3]; //static array
    double arr2[5];
    printf("array size: %zu \n", sizeof(arr)); //=12
    printf("array size: %zu \n", sizeof(arr2)); 
}