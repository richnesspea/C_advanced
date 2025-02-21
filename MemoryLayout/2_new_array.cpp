#include <iostream>
using namespace std;

int main(){
    int *ptr = new int[10];
    if (!ptr)
    {
        cout << "Memory allocation failed\n";
    }
    else {
        cout << "Memory allocation succeeded\n";
    }

}