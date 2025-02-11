#include <stdio.h>
int f(int x, int *py, int **ppz) 
{ 
  int y, z; 
  **ppz += 1; // c++ -> c = 5
   z  = **ppz; // z = c -> z = 5
  *py += 2; //c = c +2 -> c = 7
   y = *py;// y = c -> y = 7
   x += 3; // x = 4 +3  = 7 -> Đây chỉ là copy của biến c lúc chưa được tăng giá trị
   return x + y + z; // 7 + 7 + 5 = 19
} 
   
int main() 
{ 
   int c, *b, **a; 
   c = 4; 
   b = &c;  //Lưu địa chỉ của biến c vào con trỏ b 
   a = &b;  //Lưu địa chỉ của con trỏ b vào con trỏ bậc 2 a
   printf("%d ", f(c, b, a)); 
   return 0;
}
