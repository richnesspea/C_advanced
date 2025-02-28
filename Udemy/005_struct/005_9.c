#include <stdio.h>
/*
Data alignment: còn căn chỉnh dựa theo kích thước của bội số của thằng lớn nhất. Ví dụ trong Struct A thì là biến val2 (int 4 bytes)
*/
typedef struct {
    short val1; // 2 bytes
    int val2;   // 4 bytes
    char val3;  // 1 byte
}A;

typedef struct {
    char val1; //1 byte
    int val2; //4 bytes
    A val3; // 12 bytes
}B;

int main(){
    unsigned int totalBytesA = sizeof(A);
    unsigned int totalBytesB = sizeof(B);
    printf("%d\n", totalBytesA);
    printf("%d\n", totalBytesB);
}