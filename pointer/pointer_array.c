#include <stdio.h>
#include <stdint.h>
int main(){
    int arr[5] = {1, 2, 3, 4, 5};
    uint8_t arr1[5] = {1, 2, 3, 4, 5};
    uint32_t arr2[5] = {1, 2, 3, 4, 5};
    uint32_t var1;

    int *p = arr;    // Hợp lệ, arr là địa chỉ của phần tử đầu tiên
    p = p + 1;       // Hợp lệ, p có thể thay đổi
    //arr = arr + 1;   // Lỗi! Không thể gán lại tên của mảng
    
    printf("%d\n", p);
    printf("%d\n", arr);

    printf("%d\n", *p);
    printf("%d\n", *arr);

    uint8_t *p1 = &arr1[1]; // Trỏ tới arr[1]
    uint8_t *p2 = &arr1[4]; // Trỏ tới arr[4]

    uint32_t *p3 = &arr2[0]; // Trỏ tới arr[1]
    uint32_t *p4 = &arr2[4]; // Trỏ tới arr[4]
    uint32_t *p5 = &var1;
    
    // Phép trừ giữa hai con trỏ
    int diff = p2 - p1;  // diff sẽ là số lượng phần tử giữa p1 và p2
    printf("value of p1 is: %p\n", p1);
    printf("value of p2 is: %p\n", p2);
    printf("Difference between p2 and p1: %d\n", diff);
    printf("size of arr1: %zu\n", sizeof(arr1));

    //p4 - p1
    int diff2 = p5 - p3;  // diff sẽ là số lượng phần tử giữa p5 và p3
    printf("value of p3 is: %p\n", p3);
    printf("value of p4 is: %p\n", p4);
    printf("value of p5 is: %p\n", p5);
    //printf("Difference between p4 and p3: %d\n", diff2);
    printf("Difference between p5 and p4: %d\n", diff2);
    printf("size of arr2: %zu\n", sizeof(arr2));

}