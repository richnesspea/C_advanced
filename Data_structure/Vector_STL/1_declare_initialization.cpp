#include <bits/stdc++.h>
using namespace std;

void printV(vector<int> &v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main() {

    // Creating an empty vector
    vector<int> v1;

    // Creating a vector of 5 elements from
    // initializer list
    vector<int> v2 = {1, 4, 2, 3, 5};

    // Creating a vector of 5 elements with
    // default value
    vector<int> v3(5, 9);

    printV(v1);
    printV(v2);
    printV(v3);

    return 0;
}
