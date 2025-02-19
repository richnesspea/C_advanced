#include <iostream>
using namespace std;

class Base {
public:
    virtual void show() {  // Virtual function (Dynamic Binding)
        cout << "Base class show() function" << endl;
    }
};

class Derived : public Base {
public:
    void show() {  // Overriding Base's show()
        cout << "Derived class show() function" << endl;
    }
};

int main() {
    Base* ptr;
    Derived obj;
    ptr = &obj;  // Base class pointer pointing to Derived object

    ptr->show();  // Calls Derived::show() due to dynamic binding

    return 0;
}
