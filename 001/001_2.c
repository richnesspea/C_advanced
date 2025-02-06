#include <stdio.h>


void swap(int num1, int num2){
    int temp;
    printf("num1 before swap = %d \n", num1);
    printf("num2 before swap = %d \n", num2);
    temp = num1;
    num1 = num2;
    num2 = temp;
    printf("num1 after swap = %d \n", num1);
    printf("num2 after swap = %d \n", num2);
}

void main(){
    int a = 5, b = 7;
    swap(a, b);
}