#include<stdio.h> 
int  main() 
{ 
    unsigned int x = -1; 
    int y = ~0; 
    printf("%d\n", x);
    printf("%d\n", y); 
    if (x == y) 
        printf("same"); 
    else
        printf("not same"); 
    return 0; 
}