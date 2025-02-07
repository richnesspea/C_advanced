// C Program to illustrate the use of user-defined function
#include <stdio.h>
 
// Function prototype
int sum(int, int);
int sum2(int*, int*);
 
// Function definition
int sum(int x, int y)
{
    int sum;
    sum = x + y;
    return x + y;
}


int sum2 (int *x, int *y){
    return *x + *y;
}

 
// Driver code
int main()
{
    int x = 10, y = 11;
 
    // Function call
    int result = sum(x, y);
    int result2 = sum2(&x, &y);
    printf("Sum using pass by value of %d and %d = %d \n", x, y, result);
    printf("Sum using pass by reference of %d and %d = %d \n", x, y, result2);
    return 0;
}