#include <iostream>
using namespace std;

class Base {
private:
    int y;
    int z;

public:

    Base (int Y, int Z) : y(Y), z(Z){}
    int x = 10;

    // Provide a getter method to access private members (optional if 'x' is public)
    int getX() const { return x; }
};

// Define operator<< outside the class, but not as a friend function
ostream& operator<<(ostream& COUT, const Base& obj) {
    COUT << "the value that ptr2 points to is " << obj.x << endl;
    return COUT;
}

int main() {
    int *ptr = new int;
    *ptr = 10;

    int *ptr3 = new int(10);
    Base *ptr2 = new Base(25, 50); 
    ptr2->x = 20;

    cout << "The address of ptr is " << ptr << endl;
    cout << "The value that ptr points to is " << *ptr << endl;

    cout << "The address of ptr3 is " << ptr3 << endl;
    cout << "The value that ptr3 points to is " << *ptr3 << endl;   
    
    cout << "The address of ptr2 is " << ptr2 << endl;
    cout << *ptr2 << endl;  // Calls overloaded << operator

    // Free allocated memory
    delete ptr;
    delete ptr2;
    delete ptr3;

    return 0;
}
