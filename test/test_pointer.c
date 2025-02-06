#include <stdio.h>
int *ptr;

void func1(){
    int a =5;
    ptr = &a;
}

int main(){
    func1();
    return 0;
}