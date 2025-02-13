#include <stdio.h>
 
int main()
{
   float c = 5.0;
   printf ("Temperature in Fahrenheit is %.2f\n", (9/5)*c + 32);//In C, when both operands of the division (9 and 5) are integers, the division result is also an integer.
   printf ("Temperature in Fahrenheit is %.2f\n", (9.0/5.0)*c + 32);
   printf ("Temperature in Fahrenheit is %.2f\n", (9.0/5)*c + 32);
   printf ("Temperature in Fahrenheit is %.2f\n", (9/5.0)*c + 32);
   
   
   return 0;
}