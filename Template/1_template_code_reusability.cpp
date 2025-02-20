#include <iostream>

// 1. Function Overloading (Less Reusable, More Code)
void print(int x) {
    std::cout << "Integer: " << x << std::endl;
}
void print(double x) {
    std::cout << "Double: " << x << std::endl;
}
void print(const std::string& x) {
    std::cout << "String: " << x << std::endl;
}


template <typename T> //Template declaration
void printTemplate(const T& x){
    std::cout << "Template: " << x << std::endl;
}


template <typename U>  // Template declaration
U minimum(const U& lhs, const U& rhs) {  // Generic function
    return lhs < rhs ? lhs : rhs;
}


int main(){
    print(5);
    print(5.0);
    print("LongDoQuang");

    printTemplate(10);
    printTemplate(10.5);
    printTemplate("LongDoQuang");

    int a = 10, b = 20;
    int result = minimum<int>(a,b);
    std::cout << "The result of template Minimum is: " << result << std::endl;

}