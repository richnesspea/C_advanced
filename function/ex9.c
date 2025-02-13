#include <stdio.h>
 
int main()
{
   int a = 1;
   int b = 1;
   //int c = a || --b; // as a = 1 and c = 1 and --b is not run -> b continues to be equal to 1
   int c = --b || a;
   printf("b: %d \n", b);
   int d = a-- && --b; 
   printf("b: %d \n", b);
   printf("a = %d, b = %d, c = %d, d = %d", a, b, c, d);
   return 0;
}