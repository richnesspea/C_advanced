#include <iostream>

int& getLocalVariable() {
    int x = 42;  // Local variable
    return x;    // Return reference to local variable (bad practice)
}

int main() {
    int& ref = getLocalVariable();  // ref is now a dangling reference
    std::cout << "Value of ref: " << ref << std::endl;  // Undefined behavior
    return 0;
}
