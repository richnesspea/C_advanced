#include<iostream>
using namespace std;
class TestClass {
    private:
        static int var1;//static member can only accessed through member functions  like func1 or func2
        static void func1(int& v1, int& v2){
            int temp = v1;
            v1 = v2;
            v2 = temp;
        }
        void func3(){
            cout << "this is private non-static member function" << endl;
        }
    public:
        static int var2;// public static var -> can be accessed by both objects and class's name
        int var3; //non-static var -> cannot accessed by class's name, only accessed by object
        static int func2(int v1, int v2);
};

int TestClass::func2(int v1, int v2){
    return v1 + v2;
}

// int TestClass::var1 = 5;
// int TestClass::var2 = 10;

int main(){
    cout << TestClass::var2 << endl;
    //cout << TestClass::var1 << endl; compile error as var1 is static var, so it cann't accessed through class name, but the class's member functions.

    TestClass obj1;
    obj1.var3 = 1; 
    cout <<TestClass::func2(obj1.var2, obj1.var3) << endl;
}
