#include <iostream>
using namespace std;

namespace first_place{
    class Class1{//Class1 is declared and defined inside namespace
    public:
        Class1(){
            cout << "This is Class from first_place" << endl;
        }
    };

    class Class2;//Class2 is declared inside namespace
}


class first_place::Class2{////Class2 is defined outside namespace 
public:
    Class2(){
        cout << "This is Class2 from first_place" << endl;
    }
}; 

int main(){
    first_place::Class1 obj1;
    first_place::Class2 obj2;
}
