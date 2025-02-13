// C++ Program to demonstrate that
// Members of a class are private
// by default
#include <iostream>

using namespace std;

class Test_class {
    // x is private
    int x;
};

struct Test_struct {
    // x is public
    int x;
};

int main() {
    Test_struct t;
    Test_class c;

    // compiler error because x
    // is private
    //c.x = 20;

    t.x = 20;
    std::cout << t.x << std::endl;

    return 0;
}
