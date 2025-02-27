#include <bits/stdc++.h>
using namespace std;

int main() {
    list<int> l = {1, 3, 4, 2, 5};
    
    // Changing the first element
    l.front() = 11;
    
    // Move iterator to the second element
    auto it = l.begin();
    advance(it, 2);
    
    // Update the value using iterator
    *it = 10;
    
    for (auto i : l) 
        cout << i << " ";
    return 0;
}
