#include <stdio.h>
#include <string.h>
#include <stdint.h>

int main() {
    // Khai báo hai chuỗi
    uint8_t haystack[] = "AT OK AT   OK AT OK AT OK AT OK";
    char needle[] = "OK";

    // Tìm chuỗi "AT   OK" trong "OK AT   OK AT OK AT OK AT OK"
    char *result = strstr((char *)haystack, needle);

    // Kiểm tra kết quả
    if (result != NULL) {
        printf("Chuoi \"%s\" duoc tim thay tai vi tri: %ld\n", needle, (intptr_t)(result - (char *)haystack));
    } else {
        printf("Chuoi \"%s\" khong duoc tim thay.\n", needle);
    }

    return 0;
}
