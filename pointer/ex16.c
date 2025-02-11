#include <stdio.h>
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int *p = arr;
    ++*p;// arr[0] = 2
    printf("%d", *p);
    p += 2;// p trỏ tới arr[2]
    printf("%d", *p);// *p = arr[2] = 3;
    return 0;
}
