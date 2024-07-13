#include <stdio.h>

void main(){
    int a = 5, b= 7;
    int temp;
    temp = a;
    a = b;
    b = temp;
    printf("value of a = %d \n", a);
    printf("value of b = %d \n", b);
}