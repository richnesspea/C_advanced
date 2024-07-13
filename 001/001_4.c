#include <stdio.h>

int main(){
    int a = 5;
    int *p;

    printf("%p \n",&a);
    printf("%p \n",p);

    //printf("%d",*p); : Gặp lỗi vì đang cố in giá trị mà con trỏ p đang trỏ tới trong khi con trỏ p này 
    //dù đã được khai bao nhưng chưa trỏ tơi một địa chỉ hợp lí 
    //int *q = NULL;
    //printf("%d",*q);
    
    p = &a;
    printf("%p after \n",p);
    printf("%d after \n",*p);

    *p = 7;
    printf("%p after2 \n",p);
    printf("%d after2 \n",*p);

    *p = 9;
    printf("%d after3 \n",*p);

    
}