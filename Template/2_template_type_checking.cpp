#include <iostream>

// Template function enforcing strong type checking
template <typename T>
T add(T a, T b) {
    return a + b;
}

int main() {
    int x = 5, y = 10;
    double p = 5.5, q = 2.5;

    std::cout << "Sum of integers: " << add(x, y) << std::endl;      // Works
    std::cout << "Sum of doubles: " << add(p, q) << std::endl;      // Works
    
    //std::cout << add(x, p); // ERROR: Mixing int and double

    return 0;
}
