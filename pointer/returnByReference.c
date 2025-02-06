#include <stdio.h>

int* findMax(int* a, int* b){
    return(*a > *b) ? a : b;
}


int main(){
    int x = 70;
    int y = 50;
    int *maxPtr = findMax(&x, &y);
    printf("the max of x and y is %d\n", *maxPtr);
    printf("the address of x and y is %p and %p \n",&x, &y);
    printf("the address of maxPtr is %p \n", maxPtr);
    *maxPtr = 100;
    printf("the value of x and y is %d and %d \n",x, y);
}