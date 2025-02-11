#include<stdio.h>
int main()
{
    int arr[] = {10, 20, 30, 40, 50, 60};
    double arr3[] = {10.0, 20.0, 30.0, 40.0, 50.0, 60.0};
    char arr2[] = {'a', 'b', 'c', 'd'};
    int *ptr1 = arr;
    int *ptr2 = arr + 5;
    char *ptr3 = arr2;
    char *ptr4 = arr2 + 3;
    double *ptr5 = arr3;
    double *ptr6 = arr3 + 4;

    //(char*)ptr2: khi ép kiểu như thế này, đánh dấu là vùng nhớ thao tác với con trỏ ptr2 có độ lớn là sizeof(char) byte = 1 byte
    //Vì vậy nếu (char*)ptr2 - (char*)ptr1 sẽ tính ra được số byte giữa 2 con trỏ
    //Về mặt bản chất ptr2 - ptr1: dùng để tính được số phần tử giữa 2 vùng nhớ mà 2 con trỏ ptr1 và ptr2 đang trỏ tới.
    printf("Number of elements between two pointer are: %d\n",  (ptr2 - ptr1));
    printf("Number of elements between two pointer are: %d\n",  (int*)ptr2 - (int*) ptr1);
    printf("Number of bytes between two pointers are: %d\n",  (char*)ptr2 - (char*) ptr1);
    
    printf("The address of value is: %d\n", &ptr2);
    printf("The value of ptr2 is: %d\n",  ptr2);
    printf("when typecast pointer is: %d\n", (int*)ptr2);
    printf("when typecast pointer is: %d\n", (char*)ptr2);

    printf("Number of bytes between two pointers are: %d\n",  (char*)ptr4 - (char*) ptr3);
    printf("Number of bytes between two pointers are: %d\n",  (char*)ptr6 - (char*) ptr5);
    return 0;
}
