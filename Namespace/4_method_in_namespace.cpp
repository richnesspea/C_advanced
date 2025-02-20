#include <iostream>
using namespace std;

namespace first_place{
    class Class1{
    public:
        Class1(){
            cout << "This is Class from first_place" << endl;
        }
        void Method1(){//method declared and defined inside namespace
            cout << "This is Method1 inside the Class" << endl;
        }
        int Method2(const int &x, const int &y);//method declared inside namespace
    };
}

int first_place::Class1::Method2(const int &x, const int &y){//method defined outside namespace
    return x + y;
}



int main(){
    first_place::Class1 obj1;
    obj1.Method1();
    cout << "The result of Method2 declared inside ns and defined outside ns is: " << obj1.Method2(4, 5) << endl;
}
