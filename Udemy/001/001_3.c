#include <stdio.h>

void swap(int num1, int num2){
    int temp;
    temp = num1;
    num1 = num2;
    num2 = temp;
}

void main(){
    int a = 5, b = 7;
    printf("a before swap = %d \n", a);
    printf("b before swap = %d \n", b);
    swap(a, b);
    printf("a after swap = %d \n", a);
    printf("b after swap = %d \n", b);
}