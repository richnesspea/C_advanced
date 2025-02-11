#include<stdio.h>
 
void swap (char *x, char *y)
{
    char *t = x; 
    x = y;
    y = t;
}
 
int main()
{
    char *x = "AAAA";
    char *y = "BBBB";
    char *t;
    swap(x, y);//Truyền địa chỉ đầu tiên của 2 mảng kí tự "AAAA" và "BBBB"
                //Cũng chỉ là 2 địa chỉ được copy đổi chỗ cho nhau. Còn sau khi thoát ra khỏi swap function thì bên ngoài
                //về main thì không thay đổi. 
    printf("(%s, %s)\n", x, y);
    t = x;
    x = y;
    y = t;
    printf("(%s, %s)\n", x, y);
    return 0;
}

