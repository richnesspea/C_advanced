#include "1_header.h"


void InitArray(Array *arr, int capacity) {
    if (capacity <= 0 || capacity > MAX) {
        printf("Invalid capacity!\n");
        return;
    }
    arr->address = (int *)malloc(capacity * sizeof(arr->address[0]));
    if (!arr->address) {
        printf("Memory allocation failed!\n");
        return;
    }
    arr->capacity = capacity;
    arr->size = 0;
}

bool AddElement(Array *arr, int value) {
    if (arr->size >= arr->capacity) {
        printf("Array is full!\n");
        return false;
    }
    arr->address[arr->size++] = value;
    return true;
}

bool DelElement(Array *arr, int index) {
    if (index < 0 || index >= arr->size) {
        printf("Invalid index!\n");
        return false;
    }
    for (int i = index; i < arr->size - 1; i++) {
        arr->address[i] = arr->address[i + 1];
    }
    arr->size--;
    return true;
}

void PrintArray(Array *arr) {
    for (int i = 0; i < arr->size; i++) {
        printf("%d ", arr->address[i]);
    }
    printf("\n");
}

void freeArray(Array *arr) {
    free(arr->address);
    arr->address = NULL;
    arr->capacity = 0;
    arr->size = 0;
}

void Sort(Array *arr) {
    for (int i = 0; i < arr->size - 1; i++) {
        for (int j = 0; j < arr->size - i - 1; j++) {
            if (arr->address[j] > arr->address[j + 1]) {
                int temp = arr->address[j];
                arr->address[j] = arr->address[j + 1];
                arr->address[j + 1] = temp;
            }
        }
    }
}

bool Search(Array *arr, int value) {
    for (int i = 0; i < arr->size; i++) {
        if (arr->address[i] == value) {
            return true;
        }
    }
    return false;
}