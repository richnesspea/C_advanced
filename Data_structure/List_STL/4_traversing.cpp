#include <bits/stdc++.h>
using namespace std;

int main() {
    list<int> l = {1, 3, 4, 2, 5};

    // Traversing using iterators
    for (list<int>::iterator it = l.begin(); it != l.end(); ++it) // When it != l.end() is True the loop continues 
        cout << *it << " ";
    return 0;
}
