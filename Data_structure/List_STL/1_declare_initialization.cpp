#include <bits/stdc++.h>
using namespace std;

void printL(list<int>& l) {
    for (auto i : l)
        cout << i << " ";
    cout << '\n';
}

int main() {
    
    // Creating an empty list
    list<int> l1;

    // Creating list from initializer list
    list<int> l2 = {1, 3, 4, 2, 5};

    // Creating list with default value
    list<int> l3(5, 9);
    
    printL(l1);
    printL(l2);
    printL(l3);
    return 0;
}
