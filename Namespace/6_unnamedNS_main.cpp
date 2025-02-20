#include "6_unnamedNS_myheader.h"


//extern int counter; -> cause errors
//class derived : public Helper {}; -> cause errors

extern int global_counter;
int main() {
    displayMessage(); // Calls the function from the linked file (file1.cpp or file2.cpp)

    Printer myPrinter;
    myPrinter.print(); // Calls the method from the linked file
    global_counter++;
    return 0;
}
