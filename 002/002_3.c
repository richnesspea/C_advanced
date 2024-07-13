#include <stdio.h>

int main(){
    int *ptr1;
    double *ptr2;
    int grade1 = 80;
    double grad2 = 80.5;

    printf("size of grade1 = %zu\n", sizeof(grade1));
    printf("size of ptr1 = %zu\n", sizeof(ptr1)); //Trên hệ thống 64-bit thì kích thước của con trỏ thường là 8 byte
    printf("size of ptr2 = %zu\n", sizeof(ptr2));
    ptr1 = &grade1;
    printf("size of ptr1 = %zu\n", sizeof(ptr1)); //Phép gán không thay đổi bản thân kích thước của con trỏ mà chỉ thay đổi giá trị mà con trỏ đang trỏ tới

    int arr[6];
    printf("Address of array: %p \n", arr);
    printf("Size of Array: %zu \n", sizeof(arr));
    ptr1 = arr; //Gán địa chỉ của phần tử đầu tiên của mảng cho con trỏ ptr1
    printf("size of ptr1: %zu \n", sizeof(ptr1));

}