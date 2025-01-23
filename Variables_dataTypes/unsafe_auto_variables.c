#include <stdio.h>

int* unsafePointer() {
    int localVar = 10;  // auto variable
    return &localVar;   // returning the address of a local variable
}

int main() {
    int *ptr = unsafePointer();
    printf("Value: %d\n", *ptr);  // Undefined behavior
    return 0;
}
