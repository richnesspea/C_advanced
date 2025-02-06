#include <stdio.h>

void swap_value(int num1, int num2){
    int temp;
    temp = num1;
    num1 = num2;
    num2 = temp;
    printf("a after swap in swap_value function = %d \n", num1);
    printf("b after swap in swap_value function = %d \n", num2);
}

void swap_reference(int *num1, int *num2){
    int temp;
    temp = *num1;
    *num1 = *num2; //Thay đổi giá trị của 2 biến mà con trỏ num1 và num2 trỏ tới.
    *num2 = temp;
    printf("a after swap in swap_reference function = %d \n", *num1);
    printf("b after swap in swap_reference function = %d \n", *num2);
}


void main(){
    int a = 5, b = 7;
    printf("a before swap = %d \n", a);
    printf("b before swap = %d \n", b);
    swap_value(a, b);
    printf("a after swap_value in main function = %d \n", a);
    printf("b after swap_value in main function = %d \n", b);
    swap_reference(&a, &b); //Truyền địa chỉ của 2 biến a và b vào trong hàm.
    printf("a after swap_reference in main function = %d \n", a);
    printf("b after swap_reference in main function = %d \n", b);

}