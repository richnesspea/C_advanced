#include <iostream>
using namespace std;

namespace first_place{
    class Class{
        Class(){
            cout << "This is Class from first_place" << endl;
        }
    };
}

namespace second_place{
    void func1(){
        cout << "This is the second place" << endl;
    }
}

using namespace first_place;

int main(){

}
