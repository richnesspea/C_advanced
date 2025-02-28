#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main() {
    uint16_t *aptr = NULL; // Pointer to store user input values
    uint16_t *bptr = NULL; // Pointer to store max value address
    int num_elements;

    printf("Enter the number of elements: ");
    scanf("%d", &num_elements);

    if (num_elements <= 0 || num_elements >= 255) {
        printf("Invalid number of elements!\n");
        return 1;
    }

    aptr = (uint16_t *)malloc(num_elements * sizeof(uint16_t));
    if (!aptr) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Get input values
    printf("Enter %d positive integers:\n", num_elements);
    for (int i = 0; i < num_elements; i++) {
        printf("Element [%d]: ", i);
        scanf("%d", &aptr[i]);
    }

    // Find the maximum value and its address
    bptr = aptr; 
    for (int i = 1; i < num_elements; i++) {
        if (aptr[i] > *bptr) {
            bptr = &aptr[i];
        }
    }

    // Print values in reverse order with memory addresses
    printf("\nElements in reverse order with addresses:\n");
    for (int i = num_elements - 1; i >= 0; i--) {
        printf("%p: %hu\n", &aptr[i], aptr[i]);
    }

    // Print max value and its address
    printf("\nMax value: %hu at address %p\n", *bptr, bptr);
    free(aptr);

    return 0;
}
