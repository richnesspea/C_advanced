#include <iostream>
using namespace std;

class base {
public:
    virtual void fun_2() { cout << "base-2\n"; }
    virtual void fun_3() { cout << "base-3\n"; }
    virtual void fun_4() { cout << "base-4\n"; }
};

class derived : public base {
public:
    int x;
    void fun_2() override { cout << "derived-2\n"; }
    void fun_4(int x) { cout << "derived-4\n"; }  // Overloaded, not overridden
    virtual void fun_5() { cout << "derived-5\n"; }
};

class derived2 : public derived {
public:
    int y;
    void fun_5() { cout << "derived2-5\n"; }
};

int main() {

    cout << "The size of Base class: " << sizeof(base) << endl;
    cout << "The size of Derived class: " << sizeof(derived) << endl;
    cout << "The size of Derived2 class: " << sizeof(derived2) << endl;

    return 0;
}
