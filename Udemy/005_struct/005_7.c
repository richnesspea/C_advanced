#include <stdio.h>
#include <stdint.h>

typedef struct{
    char x;//1 byte  => 2000
    double y; // 8byte => 2004
    int z; // 4byte
}Point;

int main(){
    uint8_t sizeof_Point = sizeof(Point);
    printf("%d \n", sizeof_Point);
}