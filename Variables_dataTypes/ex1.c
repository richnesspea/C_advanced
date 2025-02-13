#include<stdio.h> 
int  main() 
{ 
    unsigned int x = -1; 
    int y = ~0; 
    printf("%d\n", x); //it continues to print -1 as %d indicates that it needs signed integer -> need changing to %u
    printf("%d\n", y); // 0 indicates 00000000 00000000 00000000 00000000
                        //~0 indicates 11111111 11111111 11111111 11111111
    if (x == y) 
        printf("same"); 
    else
        printf("not same"); 
    return 0; 
}