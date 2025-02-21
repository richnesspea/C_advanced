#include <iostream>
using namespace std;
template <class T>
void MySwap(T& a, T& b) {
    T c(a); // Copy a to temporary variable c
    a = b;  // Assign b to a
    b = c;  // Assign c (original a) to b
}

int main() {
    int x = 10;
    double y = 25.5;
    //MySwap(x, y);  // cause errors
    cout << x << " " << y << endl;
}