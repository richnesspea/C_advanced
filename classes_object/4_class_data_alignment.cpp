#include <iostream>

class Example {
public:
    char a;     // 1 byte
                // 3 bytes of padding
    int b;      // 4 bytes
    short c;    // 2 bytes
                // 2 bytes of tail padding
};

int main() {
    Example obj;

    // Print the size of each individual member
    std::cout << "Size of char a: " << sizeof(obj.a) << " byte" << std::endl;
    std::cout << "Size of int b: " << sizeof(obj.b) << " bytes" << std::endl;
    std::cout << "Size of short c: " << sizeof(obj.c) << " bytes" << std::endl;

    // Print the size of the entire class
    std::cout << "Size of Example class: " << sizeof(Example) << " bytes" << std::endl;

    return 0;
}
