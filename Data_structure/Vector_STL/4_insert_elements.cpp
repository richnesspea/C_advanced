#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<char> v = {'a', 'f', 'd'};

    v.push_back('y');
    v.push_back('z');

    v.insert(v.begin() + 1, 'c');
    v.insert(v.begin() + 1, 'b');

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    return 0;
}
