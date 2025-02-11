#include <stdio.h>
 
int main()
{
    int arri[] = {1, 2 ,3};
    int *ptri = arri;
 
    char arrc[] = {1, 2 ,3};
    char *ptrc = arrc;
 
    printf("sizeof arri[] = %d ", sizeof(arri));  //12 # sizeof(arri[0])
    printf("sizeof ptri = %d ", sizeof(ptri));  //4
 
    printf("sizeof arrc[] = %d ", sizeof(arrc));//3
    printf("sizeof ptrc = %d ", sizeof(ptrc));//4
 
    return 0;
}