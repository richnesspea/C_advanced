#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int *createArray();

void printArr(int *arr, int size){
    for(int i = 0; i < size; i++){
        printf("%d \n", arr[i]);
    }
}

int main(){
    int *arr = createArray();
    printArr(arr, SIZE);
    free(arr);
}

int *createArray(){
    int *myArr = (int *)malloc(SIZE * sizeof(int));
    if(!myArr){
        printf("Memory allocation failed!");
        exit(1); //exit immediately
    }

    printf("Enter %d elements for your array:\n", SIZE);
    for(int i = 0; i < SIZE; i++){
        printf("Enter number %d: ", i+1); // Hiển thị rõ số thứ tự
        while(scanf("%d", &myArr[i]) != 1) { // Kiểm tra nhập liệu hợp lệ
            printf("Invalid input. Please enter an integer: ");
            while(getchar() != '\n'); // Xóa bộ đệm nếu nhập sai
        }
    }
    return myArr;
}
