#include <iostream>
#include "6_unnamedNS_myheader.h"
int global_counter = 0;

namespace {
    int counter = 10;  // This variable is only visible in file1.cpp

    class Helper {  // Internal class only accessible in file1.cpp
    public:
        void assist() {
            std::cout << "Helper class assisting in file1.cpp\n";
        }
    };
}

class derived : public Helper {};

void displayMessage() {
    std::cout << "Message from file1.cpp (Counter: " << counter << ")" << std::endl;
}

void Printer::print() {
    Helper helper;
    helper.assist();
    std::cout << "Printer class printing from file1.cpp\n";
}

