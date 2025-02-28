#include <stdio.h>

// int findMinMax(int num1, int num2){
//     int min, max;
//     if(num1 > num2){
//         max = num1;
//         min = num2;
//     }
//     else {
//         max = num2;
//         min = num1;
//     }
//     return min, max;
// }

//Có thể sử dụng Pointer hoặc struct

void findMinMax(int num1, int num2, int *pMin, int *pMax){
    if(num1 > num2){
        *pMax = num1;
        *pMin = num2; 
    }
    else {
        *pMax = num2;
        *pMin = num1; 
    }
}

void main(){
    int a = 5, b = 7;
    int min, max;
    findMinMax(a, b, &min, &max);
    printf("%d \n",min);
    printf("%d \n",max);
}