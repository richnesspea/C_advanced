#include <stdio.h>
#include <stdint.h>

int main() {
    uint32_t num = 0x12345678;
    uint8_t *ptr = (uint8_t*)&num;

    printf("Little-endian byte order:\n");
    for (int i = 0; i < 4; i++) {
        printf("Byte %d: 0x%X\n", i, ptr[i]);
    }

    return 0;
}
