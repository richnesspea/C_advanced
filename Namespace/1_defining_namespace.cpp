#include <iostream>
using namespace std;

namespace first_place{
    void func1(){
        cout << "This is the first place" << endl;
    }
}

namespace second_place{
    void func1(){
        cout << "This is the second place" << endl;
    }
}

using namespace first_place;

int main(){
    func1();
    //second_place::func1();
    return 0;
}
