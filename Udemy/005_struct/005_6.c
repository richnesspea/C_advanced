#include <stdio.h>
#include <stdint.h>

typedef struct{
    char x;
    short y;
    int z;
}Point;

int main(){
    uint8_t totalStructBytes = sizeof(Point);
    Point p1;
    p1.x = 0xFF; //1 byte of memory
    p1.y = 0x1234; // 2 bytes of memory
    p1.z = 0x6789ABCD; //4 bytes of
}