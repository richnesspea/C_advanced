#include <stdio.h>

int main(){
    int *p;
    int a;
    p = &a;

    double *p2;
    double b = 10.5;
    p2 = &b;

    printf("the size of pointer p is: %zu\n", sizeof(p));
    printf("the size of var that pointer p points to is: %zu\n", sizeof(*p));
    
    printf("the size of pointer 2p is: %zu\n", sizeof(p2));
    printf("the size of var that pointer p2 points to is: %zu\n", sizeof(*p2));
    

    return 0;
}