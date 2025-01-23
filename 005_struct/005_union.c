#include <stdio.h>

union Data {
    int i;
    float f;
    char str[20];
};

int main() {
    union Data data;

    data.i = 10;
    printf("data.i = %d\n", data.i);

    data.f = 220.5;
    printf("data.f = %.1f\n", data.f);

    // Ghi đè giá trị, nội dung cũ bị mất
    snprintf(data.str, sizeof(data.str), "Hello");
    printf("data.str = %s\n", data.str);

    // Giá trị của data.i và data.f bị mất do ghi đè bởi data.str
    printf("data.i = %d\n", data.i);

    return 0;
}
