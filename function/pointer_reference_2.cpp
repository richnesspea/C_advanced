#include <iostream>

int main() {
    int* ptr = nullptr;  // Pointer assigned nullptr (valid)
    if (ptr == nullptr) {
        std::cout << "Pointer is null.\n";
    }

    int a = 42;
    int& ref = a;  // Reference must be initialized with a valid variable
    std::cout << "Reference refers to a: " << ref << std::endl;

    // Trying to assign NULL or nullptr to a reference will cause a compilation error.
    // Uncommenting the following line will generate an error:
    //int& refNull = nullptr;

    return 0;
}