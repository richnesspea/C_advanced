#include <stdio.h>
 
int main()
{
    float arr[5] = {12.5, 10.0, 13.5, 90.5, 0.5};
    float *ptr1 = &arr[0];
    float *ptr2 = ptr1 + 3; //address of 90.5: arr[3]
 
    printf("%f ", *ptr2);//90.5
    printf("%d", ptr2 - ptr1); //3
 
   return 0;
}