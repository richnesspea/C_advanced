#include<iostream> 
using namespace std; 
  
// A class without user defined assignment operator 
class Test 
{ 
    int *ptr; 
public: 
    Test (int i = 0)      { ptr = new int(i); } 
    void setValue (int i) { *ptr = i; } 
    void print()          { cout << *ptr << endl; } 

    // Assignment operator (Deep Copy)
    Test& operator=(const Test &other) {
        if (this != &other) { // Prevent self-assignment
            delete ptr; // Free old memory
            ptr = new int(*other.ptr); // Allocate new memory and copy value
        }
        return *this;
    }

}; 

  
int main() 
{ 
    Test t1(5); 
    Test t2; 
    t2 = t1; 
    t1.setValue(10); 
    t2.print(); 
    return 0; 
} 