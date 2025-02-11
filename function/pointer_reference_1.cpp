#include <iostream>

int main() {
    int a = 42;
    int* ptr = &a;  // Pointer to 'a'
    int& ref = a;   // Reference to 'a'

    std::cout << "Address of a: " << &a << std::endl;
    std::cout << "Address stored in ptr: " << ptr << std::endl;
    std::cout << "Address of ptr (it has its own memory): " << &ptr << std::endl;
    std::cout << "Address of ref (same as a): " << &ref << std::endl;

    std::cout << "\nSize of pointer: " << sizeof(ptr) << " bytes" << std::endl;
    std::cout << "Size of reference: " << sizeof(ref) << " bytes (same as int, reference does not take extra space)" << std::endl;

    return 0;
}
