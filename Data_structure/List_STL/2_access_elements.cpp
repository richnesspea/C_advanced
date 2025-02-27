#include <bits/stdc++.h>
using namespace std;

int main() {
    list<int> l = {1, 3, 4, 2, 5};

    // Accessing first and last elements
    cout << l.front() << endl;
    cout << l.back() << endl;
    
    // Access third element
    cout << *next(l.begin(), 2);

    return 0;
}
