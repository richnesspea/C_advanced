#include <stdio.h>

//Khi có 2 define cùng 1 tham số thì sẽ có warning và thay thế lần lượt theo thứ tự từ trên xuống dưới.

#define a 10
int main()
{
  printf("%d ",a);
 
  #define a 50
 
  printf("%d ",a);
  return 0;
}