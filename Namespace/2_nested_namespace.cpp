#include <iostream>
using namespace std;

namespace OuterNamespace{
    void func1(){
        cout << "This is outerNamespace" << endl;
    }
    namespace InnerNamespace{
        void func2(){
            cout << "This is innerNamespace" << endl;
        }
    }
}


namespace NamespaceAliasing = OuterNamespace::InnerNamespace;

int main(){
    NamespaceAliasing::func2();
    return 0;
}
