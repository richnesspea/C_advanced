#include <stdio.h>
int main()
{
    if (sizeof(int) > -1)
    // sizeof(int) returns an unsigned int
    // -1 is a signed integer
    // when comparing sizeof(int) with -1, it converts -1 from signed int to unsigned int
    // So sizeof(int) is smaller than -1
        printf("Yes");
    else
        printf("No");
    return 0;
}