#include <stdio.h>
#define ISEQUAL(X, Y) X == Y
#define X 1
int main()
{
    #if ISEQUAL(X, 0)
        printf("Geeks");
    #else
        printf("QUiz");
    #endif

    // int x = ISEQUAL(0,0);
    // printf("%d \n", x);
    return 0;
}
