#include <iostream>

// Template function enforcing strong type checking
template <typename T, typename U, typename V>
void printEmployee(T name, U age, V point) {
    std::cout << "The employee " << name << " with " << age << " years old, having " << point << " point" << std::endl;
}

int main() {
    printEmployee("LongDoQuang", 22, 20.5);
    printEmployee<std::string, int, double>("HoaDangThi", 22, 21.5);
    return 0;
}
