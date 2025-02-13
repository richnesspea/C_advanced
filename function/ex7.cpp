#include <stdio.h>
int main()
{
    int i = 5, j = 10, k = 15;
    //k /= (i + j);
    //int x = printf("Qui123\n");

    //printf("%d ", sizeof(k /= i + j));  // sizeof(k /= i + j) is determined at the compile time. 
    //printf("%d", k); //k is not actually calculated here.   
    //printf("%d", x);
    printf("%d ", sizeof(printf("Quiz\n")));
    return 0;
}
