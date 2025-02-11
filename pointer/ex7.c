#include<stdio.h> 
int main() 
{ 
   int a; 
   char *x; 
   x = (char *) &a; //Mục đích để thao tác với từng byte của giá trị a
   a = 512; //Chuyển đổi từ dạng decimal 512 thành dạng hexa 0x0200 (byte) -> byte thấp (x[0]) 0x00 và byte cao 0x02 x[1]  
   x[0] = 1; 
   x[1] = 2; //0x0200 -> 0x0201
   printf("%d\n",a);
   printf("%zu\n",sizeof(int));   
   return 0; 
}