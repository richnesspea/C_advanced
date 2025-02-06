#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

// Con trỏ toàn cục (khởi tạo và chưa khởi tạo)
int *global_ptr = (int *)0x12345678;  // Initialized Data Segment
int *uninitialized_ptr;               // BSS (Uninitialized Data)

void example_stack() {
    int a = 10;
    int *p = &a;  // Con trỏ p được cấp phát trên stack
    printf("---- Stack Example ----\n");
    printf("Address of p (on stack): %p\n", (void *)&p);
    printf("Value of p (address of a): %p\n", (void *)p);
    printf("Value at address p: %d\n\n", *p);
}

void example_heap() {
    int *p = (int *)malloc(sizeof(int));  // Cấp phát vùng nhớ trên heap
    if (p == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    *p = 20;
    printf("---- Heap Example ----\n");
    printf("Address of p (on stack): %p\n", (void *)&p);
    printf("Address p is pointing to (on heap): %p\n", (void *)p);
    printf("Value at address p: %d\n\n", *p);
    free(p);  // Giải phóng bộ nhớ
}

void example_data_segment() {
    printf("---- Initialized Data Segment Example ----\n");
    printf("Address of global_ptr (in data segment): %p\n", (void *)&global_ptr);
    printf("Value of global_ptr: %p\n\n", (void *)global_ptr);
}

void example_bss() {
    printf("---- BSS (Uninitialized Data) Example ----\n");
    printf("Address of uninitialized_ptr (in BSS): %p\n", (void *)&uninitialized_ptr);
    printf("Value of uninitialized_ptr (should be NULL): %p\n\n", (void *)uninitialized_ptr);
}

int main() {
    example_stack();
    example_heap();
    example_data_segment();
    example_bss();
    return 0;
}