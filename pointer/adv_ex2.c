#include <stdio.h>
 
#define R 10
#define C 20
 
int main()
{
   int (*p)[R][C];//10 x 20 = 200 elements -> each element is a int element -> 800 bytes.
   printf("%d",  sizeof(*p));
   getchar();
   return 0;
}
