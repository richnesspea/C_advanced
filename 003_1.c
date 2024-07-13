#include <stdio.h>

int main(){
    int a = 1000;
    int *ptr1 = &a;
    int **ptr2 = &ptr1;
    printf("address of a = %p \n", &a);
    printf("address ptr1 go to: %p \n", ptr1);
    printf("value of var that ptr1 go to: %d \n", *ptr1);
    printf("address ptr2 go to: %p \n", ptr2);
    //printf("value of var that ptr2 go to: %d \n", *ptr2);
    printf("value of var that ptr2 go to: %p \n", *ptr2);
    printf("value of var that ptr2 go to: %d \n", **ptr2);
}