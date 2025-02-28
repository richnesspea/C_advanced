#include <bits/stdc++.h>
using namespace std;

int main() {
    list<int> l = {3, 2};

    // Inserting an element at the end
    l.push_back(5);//3, 2, 5

    // Inserting an element at the beginning
    l.push_front(1);//1, 3, 2, 5

    // Inserting an element at a specific position
    auto it = l.begin();
    advance(it, 2);
    l.insert(it, 4);//1, 3, 4, 2, 5
    
    for (auto i : l) 
        cout << i << " ";
    return 0;
}
