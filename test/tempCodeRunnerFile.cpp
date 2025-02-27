#include <stdio.h>
#include <stdlib.h>

int main()
{
    char hexLine[] = ":100100002146...";
    char *endptr;
    long value = strtol(hexLine + 3, &endptr, 16);
    printf("Địa chỉ: %lx\n", value);
    printf("Ký tự tiếp theo: %c\n", *endptr);
}