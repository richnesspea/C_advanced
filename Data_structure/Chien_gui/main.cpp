#include <bits/stdc++.h>
#include "my_linked_list.h"

using namespace std;

int main() {
    // forward_list<int> list({1,3,4,2});
    // auto p = list.begin();
    // p++;
    // p = list.erase_after(list.before_begin(), list.begin());
    // for(const auto &v : list) cout << *p << endl;

    singly_linked_list<int> lst(3, 100);
    lst.insert_after(lst.begin(), 5);
    lst.erase_after(lst.before_begin());
    singly_linked_list<int> lst1 = singly_linked_list<int>(5, 200);
    lst1.swap(lst);
    for(auto i=lst.begin();i!=lst.end();i=i->next) {
        cout << i->val << " ";
    }
    cout << "\n";
    for(auto i=lst1.begin();i!=lst1.end();i=i->next) {
        cout << i->val << " ";
    }
    cout << "\n";
}