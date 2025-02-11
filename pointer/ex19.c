#include <stdio.h>
#define print(x) printf("%d ", x)
int x;
void Q(int z)
{
    z += x;// z = z + x_global = x_P +x_global = 7 + 5 = 12 
    print(z);//12
}
void P(int *y)
{
    int x = *y + 2;//x_P = 7
    Q(x);
    *y = x - 1;//x_Global = 7-1 = 6
    print(x);//7
}
void main(void)
{
    x = 5;
    P(&x);
    print(x);//6
}
