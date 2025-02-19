#include <iostream>
#include <functional>
using namespace std;

int sum (int a, int b){
    return a + b;
}

int main(){
    //std::function wrapping traditional function
    std::function<int(int, int)> calc = sum;
    cout << "Sum: " << calc(4, 5) << endl;

    //std::function wrapping lambda
    std::function<int(int, int)> calc2 = [](int a, int b) { return a * b; };
    cout << "Mulplication: " << calc2(4, 5) << endl;
}

