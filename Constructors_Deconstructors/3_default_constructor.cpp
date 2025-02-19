#include <iostream>
using namespace std;
class Base{
    public:
    Base(){
        cout << "Hello from Base" << endl;
    }
};


class Derived : public Base{
    public:
    Derived(){
        cout << "Hello from Derived" << endl;
    }
};

class Another{
    private: 
        Derived derived2;//this attribute is from another class Derived
    public:
        Another(){
            cout << "Hello from Another" << endl;
        }
};


int main(){
    Another another1;
    return 0;
}