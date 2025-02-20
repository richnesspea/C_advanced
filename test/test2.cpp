#include <iostream>
using namespace std;

class base {
public:
    void fun_1() { cout << "base-1\n"; }
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
    void fun_5() override { cout << "derived2-5\n"; }
};

int main() {
    base obj_base;
    derived obj_derived;
    derived2 obj_derived2;



    // Get vptr address (first element of the object in memory)
    cout << "\nAddress of Base Vptr: " << (&obj_base) << endl; //The address of object obj_base
    cout << "Address of Derived Vptr: " << (&obj_derived) << endl;
    cout << "Address of Derived2 Vptr: " << (&obj_derived2) << endl;
    
    // Get Vtable address (vptr points to vtable)
    void** vtable_base = *(void***)&obj_base;
    void** vtable_derived = *(void***)&obj_derived;
    void** vtable_derived2 = *(void***)&obj_derived2;

    cout << "\nVTable address (Base): " << vtable_base << endl;
    cout << "VTable address (Derived): " << vtable_derived << endl;
    cout << "VTable address (Derived2): " << vtable_derived2 << endl;

    // Print function pointers from the vtable
    cout << "\nVTable (Base) Functions:" << endl;
    cout << "  fun_2: " << (void*)vtable_base[0] << endl;
    cout << "  fun_3: " << (void*)vtable_base[1] << endl;
    cout << "  fun_4: " << (void*)vtable_base[2] << endl;

    cout << "\nVTable (Derived) Functions:" << endl;
    cout << "  fun_2 (Overridden): " << (void*)vtable_derived[0] << endl;
    cout << "  fun_3: " << (void*)vtable_derived[1] << endl;
    cout << "  fun_4 (Overridden): " << (void*)vtable_derived[2] << endl;
    cout << "  fun_5: " << (void*)vtable_derived[3] << endl;

    cout << "\nVTable (Derived2) Functions:" << endl;
    cout << "  fun_2 (From Derived): " << (void*)vtable_derived2[0] << endl;
    cout << "  fun_3 (From Base): " << (void*)vtable_derived2[1] << endl;
    cout << "  fun_4 (From Base): " << (void*)vtable_derived2[2] << endl;
    cout << "  fun_5 (From Derived): " << (void*)vtable_derived2[3] << endl;

    return 0;
}
