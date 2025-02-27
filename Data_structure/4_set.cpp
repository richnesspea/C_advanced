#include<iostream>
#include <set>
using namespace std;

// operation:
//  insert
//  size


int main(){
    set<int> s;
    s.insert(100);
    s.insert(200);
    s.insert(300);
    s.insert(100);
    cout << s.size() << endl;
}