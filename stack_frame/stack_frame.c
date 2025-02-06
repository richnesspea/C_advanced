#include <stdio.h>

int func1(int a, int b){
    int c = 0;
    return 5;
}

void func3(void){
    printf("this is func3");
}

void func4(void){
    printf("this is func4");
}
void func5(int a){}
int func2(int d, int e){    //4x2 = 8 bytes
    // int f = 0;
    // int x, y, z, m, n; // 4x4 = 16 bytes
    // x = 1;
    // y = 2;
    // z = 3;
    // //m = 4;
    // //n = 5;
    // f = func1(4, 5);
    //return address; 4 bytes
    //frame pointer: 4 bytes
    // int x, y, z, t, u, v;
    // x = 1;
    // y = 2;
    // z = 3;
    // t = 4;
    // u = 5;//32
    //func3();//8
    //func4();
    //func5(4);
    //v = func1(5, 5);//16
    return 10;
}

int main(){
    int g; 
    g = func2(5, 6);
    return 0;
}