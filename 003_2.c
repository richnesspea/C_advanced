//Void universal approach -> points to an address of any type of data
/*
    * general purpose function
        - integer
        - floating-point
        - unknown types
    * returned pointer type -> dynamic memory allocation
*/
#include <stdio.h>
int main(){
    int a = 10;
    double b = 10.5;
    void *ptr = &a;
    //printf("%d", *ptr); -> explicit type casting (ép kiểu): for the system to know exactly how many bytes it should read from the address in memory 
    //we are pointing to
    printf("%d\n", *(int*)ptr);
}