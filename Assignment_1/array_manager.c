#include "array_manager.h"
#include <stdio.h>
#include <stdlib.h>

static int *array = NULL;
static int size = 0;
static int capacity = 0;

void create_array(int new_size) {
    if (new_size <= 0) {
        printf("kich thuoc khong hop le\n");
        return;
    }
    free(array);
    array = (int *)malloc(new_size * sizeof(int));
    if (!array) {
        printf("Khong the cap phat bo nho\n");
        return;
    }
    size = new_size;
    capacity = new_size;
    printf("Da tao mang voi dung luong %d phan tu.\n", capacity);
    for (int i = 0; i < size; i++) {
        printf("Phan tu [%d]: ", i);
        scanf("%d", &array[i]);
    }
}

void print_array() {
    if (size == 0) {
        printf("Mang trong\n");
        return;
    }
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

bool insert_element(int value, int position) {
    if (position < 0 || position > size || size >= capacity) {
        printf("Vi tri khong hop le hoac mang day\n");
        return false;
    }
    for (int i = size; i > position; i--) {
        array[i] = array[i - 1];
    }
    array[position] = value;
    size++;
    return true;
}

bool delete_element(int position) {
    if (position < 0 || position >= size) {
        printf("Khong co phan tu tai vi tri %d!\n", position);
        return false;
    }
    for (int i = position; i < size - 1; i++) {
        array[i] = array[i + 1];
    }
    size--;
    return true;
}

void sort_array(bool ascending) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if ((ascending && array[i] > array[j]) || (!ascending && array[i] < array[j])) {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

bool search_element(int value) {
    for (int i = 0; i < size; i++) {
        if (array[i] == value) {
            return true;
        }
    }
    return false;
}

void clear_array() {
    free(array);
    array = NULL;
    size = 0;
    capacity = 0;
    printf("MMang da bi xoa\n");
}
