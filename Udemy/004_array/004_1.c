#include <stdio.h>

/*
    Passing an array to a function: 2 ways:
        - static approach
        - pointer approach
*/

int sumArray_static_approach(int arr[], int size){
    int i, sum = 0;
    for(i = 0; i < size; i++){
        sum = sum + arr[i];
    }
    return sum;
}   



int sumArray_pointer_approach(int *ptr, int size){
    int i, sum = 0;
    for(i = 0; i < size; i++){
        sum = sum + ptr[i];
    }
    return sum;
}


int main(){
    int grades[3] = {3, 5, 7};
    int result1, result2;
    result1 = sumArray_pointer_approach(grades, 3);
    printf("result_pointer = %d \n", result1);
    
    result2 = sumArray_static_approach(grades, 3);
    printf("result_static = %d \n", result2);
}