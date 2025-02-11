#include<stdio.h>
int main()
{
    int a = 12;
    void *ptr = (int *)&a;
    //printf("%d", *ptr); //Con trỏ void thì phải ép kiểu
    printf("%d", (int*)ptr); 
    //getchar();
    return 0;
}