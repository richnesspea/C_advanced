#include <iostream>

// Example 1: Simple Class with Basic Members
class SimpleClass {
    char a;     // 1 byte
    int b;      // 4 bytes
    short c;    // 2 bytes
};

// Example 2: Class with Virtual Functions
class VirtualClass {
    char a;           // 1 byte
    virtual void func() {} // Adds vtable pointer (4 or 8 bytes depending on system)
};

// Example 3: Empty Class
class EmptyClass {};

// Example 4: Class with Inheritance
class Base {
    char a;   // 1 byte
};

class Derived : public Base {
    int b;    // 4 bytes
};

int main() {
    // Size of SimpleClass
    std::cout << "Size of SimpleClass: " << sizeof(SimpleClass) << " bytes" << std::endl;

    // Size of VirtualClass
    std::cout << "Size of VirtualClass: " << sizeof(VirtualClass) << " bytes" << std::endl;

    // Size of EmptyClass
    std::cout << "Size of EmptyClass: " << sizeof(EmptyClass) << " bytes" << std::endl;

    // Size of Base and Derived classes
    std::cout << "Size of Base: " << sizeof(Base) << " bytes" << std::endl;
    std::cout << "Size of Derived: " << sizeof(Derived) << " bytes" << std::endl;



    return 0;
}
