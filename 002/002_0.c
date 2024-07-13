#include <stdio.h>

int main(){
    int num, num2;
    printf("size of int = %zu \n", sizeof(num));
    printf("size of char = %zu \n", sizeof(char));
    printf("size of float = %zu \n", sizeof(float));
    printf("size of 'a' = %zu \n", sizeof("a")); //Cả null terminator nữa

    printf("size of vars = %zu \n", sizeof(num + num2));
    printf("size of vars 2 = %zu \n", sizeof(num) + sizeof(num2));

    double double2;
    printf("size of double = %zu \n", sizeof(double2));
}