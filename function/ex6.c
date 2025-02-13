#include <stdio.h>

int foo(int* a, int* b)
{
    int sum = *a + *b;//sum = 1 + 2 = 3
    *b = *a;// *b = 1 -> k = 1
    return *a = sum - *b;// *a = 3 - 1 = 2 -> j = 2
}

int main()
{
    int i = 0, j = 1, k = 2, l;
    l = i++ || foo(&j, &k);//1 || 2 -> l = 1 
    printf("%d %d %d %d", i, j, k, l); //1 2 1 1
    return 0;
}