#include <bits/stdc++.h>
using namespace std;

int main() {
    list<int> l = {1, 3, 4, 2, 5};

    // Deleting last element
    l.pop_back(); //1, 3, 4, 2

    // Deleting first element
    l.pop_front();//3, 4, 2
    
    // Deleting third element
    auto it = l.begin();
    advance(it, 2);
    l.erase(it);//3, 4

    for (auto i : l) 
        cout << i << " ";
    return 0;
}
