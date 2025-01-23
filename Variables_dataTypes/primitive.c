#include <stdio.h>

int main(){
    int num = 10;
    double db = 0.156;
    float flt = 3.14;
    char c = '1';

    printf("value of num is: %d\n", num);
    printf("value of db is: %lf\n", db);
    printf("value of flt is: %f\n", flt);
    printf("value of c is: %c\n", c);

    printf("size of int = %zu \n", sizeof(int));
    printf("size of char = %zu \n", sizeof(char));
    printf("size of float = %zu \n", sizeof(float));
    printf("size of 'a' = %zu \n", sizeof("a")); //Cả null terminator nữa
    printf("size of double = %zu \n", sizeof(double));
}