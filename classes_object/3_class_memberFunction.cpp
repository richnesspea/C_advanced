#include <iostream>
#include <string>
using namespace std;

class testClass{
    public:

    string str1;
    int id;

    //member function inside class
    void printid(){
        cout << id << endl;
    }
    //member function outside class, prototype
    void printname();
};

void testClass::printname(){
    cout << str1 << endl;
}

int main(){
    testClass case1;
    case1.str1 = "string1";
    case1.id = 5;

    case1.printname();
    case1.printid();
}