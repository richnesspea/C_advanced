#include<stdio.h> 
int i = 0, j = 1;
void f(int *p, int *q) 
{ 
    //con trỏ p gán với địa chỉ của i
    //con trỏ q gán với địa chỉ của j
    p = q; //cả 2 con trỏ p và q cùng trỏ tới j 
    *p = 2; //gán giá trị mà con trỏ p đang trỏ tới với giá trị =2 -> j = 2 và i giữ nguyên 
} 
 
int main() 
{ 
  f(&i, &j); 
  printf("%d %d \n", i, j); 
  getchar(); 
  return 0; 
}