#include <stdio.h>
#include <stdlib.h>

void shared_library_function() {
    printf("This is a function from the shared library!\n");

    int *shared_data = (int*)malloc(sizeof(int));
    if (!shared_data) {
        printf("Memory allocation failed!\n");
        return;
    }

    *shared_data = 42; // Giá trị ví dụ
    printf("Shared library allocated value: %d\n", *shared_data);

    free(shared_data); // Giải phóng bộ nhớ
}
