#include <stdio.h>

void fun(int *p) 
{ 
  int q = 10; 
  p = &q; 
}     
   
int main() 
{ 
  int r = 20; 
  int *p = &r; 
  fun(p); //Copy the pointer to function fun -> the modification inside fun doesn't affect the pointer. 
  printf("%d", *p); 
  return 0; 
}