#include <iostream>
#include <string>
using namespace std;

template <typename T>
T minimum(T a, T b) {
    return (a < b) ? a : b; 
}

class MyClass {
public:
    int num;
    wstring description;

    bool operator<(const MyClass& other) const {
        return num < other.num; // Compare based on num value
    }

};


int main() {
    MyClass mc1 {1, L"hello"};
    MyClass mc2 {2, L"goodbye"};
    MyClass result = minimum(mc1, mc2); 
    return 0;
}
