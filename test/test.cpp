#include <iostream>

union Data {
    int i;
    float f;
    char c;
};

Data data_global;


int main() {
    Data data;
    
    data.i = 10; 
    std::cout << "Integer: " << data.i << std::endl;

    data.f = 5.5; 
    std::cout << "Float: " << data.f << std::endl; // Overwrites `i`

    data.c = 'A'; 
    std::cout << "Char: " << data.c << std::endl; // Overwrites `f`

    return 0;
}
