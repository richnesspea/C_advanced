#include <iostream>

// Function Overloading with Default Arguments
void display(int x, int y = 10) {
    std::cout << "Function 1: x = " << x << ", y = " << y << std::endl;
}


void display(float x) {
    std::cout << "Function 2 (float): x = " << x << std::endl;
}

void display(int x, int y, int z) {
    std::cout << "Function 2 (int, int, int): x = " << x << ", y = " << y << ", z = " << z << std::endl;
}


int main() {
    display(5.5f);  // Ambiguous call
    display(5);
    display(1 , 2, 3); // Ambiguous call
    return 0;
}
