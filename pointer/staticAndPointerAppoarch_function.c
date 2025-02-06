#include <stdio.h>

void printArray_static(int arr[5]) {
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void printArray_pointer(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    printArray_static(arr);  // Passing array
    printArray_pointer(arr, 5);
    return 0;
}