#include <stdio.h>

int findMax(int num1, int num2){
    if(num1 > num2){
        return num1;
    }
    else return num2;
}
int findMin(int num1, int num2){
    if(num1 < num2){
        return num1;
    }
    else return num2;
}

void main(){
    int a = 5, b = 7;
    int max, min;
    max = findMax(a,b);
    min = findMin(a,b);
    printf("max between %d and %d = %d \n", a, b, max);
    printf("min between %d and %d = %d \n", a, b, min);
}