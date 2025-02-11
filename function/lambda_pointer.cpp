#include <iostream>
#include <vector>
#include <algorithm>

// A function for use with a function pointer
int add(int a, int b) {
    return a + b;
}

int main() {
    int x = 10, y = 20;

    // Lambda without capture
    auto lambda_no_capture = [](int a, int b) { return a + b; };

    // Lambda with capture
    auto lambda_with_capture = [x, y](int a, int b) { return a + b + x + y; };

    // Function pointer to a named function
    int (*func_ptr)(int, int) = &add;

    // Using lambdas with STL algorithm
    std::vector<int> vec = {1, 2, 3, 4, 5};
    std::cout << "Lambda with for_each: ";
    std::for_each(vec.begin(), vec.end(), [](int n) { std::cout << n * n << " "; });
    std::cout << std::endl;

    // Output comparison
    std::cout << "Lambda without capture: " << lambda_no_capture(5, 10) << std::endl;
    std::cout << "Lambda with capture: " << lambda_with_capture(5, 10) << std::endl;
    std::cout << "Function pointer: " << func_ptr(5, 10) << std::endl;

    // Memory size comparison
    std::cout << "Size of lambda_no_capture: " << sizeof(lambda_no_capture) << " bytes" << std::endl;
    std::cout << "Size of lambda_with_capture: " << sizeof(lambda_with_capture) << " bytes" << std::endl;
    std::cout << "Size of func_ptr: " << sizeof(func_ptr) << " bytes" << std::endl;

    return 0;
}
