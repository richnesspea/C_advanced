// C program to print Integer data types.
#include <stdio.h>

int main()
{
    // Integer value with positive data.
    int a = 9;

    // integer value with negative data.
    int b = -9;

    // U or u is Used for Unsigned int in C.
    unsigned int c = 89U;
    unsigned int e = -89U;

    // L or l is used for long int in C.
    long int d = 99998L;

    printf("Integer value with positive data: %d\n", a);
    printf("Integer value with negative data: %d\n", b);
    
    printf("Integer value with an long int data: %ld\n", d);
    printf("Integer value with an unsigned int data: %u\n",
           e);//4294967207 - Two's complement

    char f = 128;  // Nếu signed, giá trị này sẽ bị chuyển đổi sang giá trị âm (-128)
    printf("the value of f is: %d\n", f);

    return 0;
}