#include "4_2_header.h"
int main(){
    char arr[20];
    while(1){
        printf("Input your accout please!!!\n");
        scanf("%s", arr);
        //printf("length of arr is:%d\n", strlen(arr));
        Check_Account(arr, strlen(arr));
    }

    return 0;
}