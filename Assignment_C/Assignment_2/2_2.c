#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

bool allocate10Bytes(uint8_t *outPtr) {
    uint8_t *ptr = malloc(sizeof(uint8_t) * 10);  
    //printf("Memory allocated at address %p\n", (void*)ptr);
    if(ptr == NULL)
        return false;
    *((uint8_t**) outPtr) = ptr;
    return true;
}

int main() {
    uint8_t *ptr = NULL;
    if(allocate10Bytes((uint8_t* )&ptr)){
        printf("Memory allocated at address %p\n", ptr);
    } else {
        printf("Memory allocation failed!\n");
    }
    free(ptr);
    return 0;
}