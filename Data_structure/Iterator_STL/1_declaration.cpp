#include <iostream>
#include <vector>

int main(){
    std::vector<int> v = {10, 20, 30, 40, 50, 60};
    //explicit declaration
    std::vector<int>::iterator i1 = v.begin();
    //auto keyword
    auto i2 = v.begin();
    //assigning existing iterator
    auto i3 = i2;

    std::cout << *i1 << " " << *i2 << " " << *i3 << std::endl;
}