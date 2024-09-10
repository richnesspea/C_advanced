#include <stdio.h>
//Bởi vì các padding, kích thước của các structure trở nên cồng kềnh hơn
//Sử dụng Packing sẽ làm giảm kích thước cần có của bộ nhớ, nhưng làm ảnh hưởng đén hiệu suất của CPU

#pragma pack(1)

typedef struct{
    char x;//1 byte  => 2000
    double y; // 8byte => 2004
    int z; // 4byte
}Point;

int main(){
    unsigned int sizeof_Point = sizeof(Point);
    printf("%d \n", sizeof_Point);
}

