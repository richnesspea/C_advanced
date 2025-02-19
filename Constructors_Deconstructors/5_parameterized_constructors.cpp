#include <iostream>
using namespace std;

class A{
public:
    int data;
    A(int x = 5){
        data = x;
    }
};

int main(){
    A a1;
    cout << a1.data << endl;
    A a2(25);
    cout << a2.data << endl;
}
