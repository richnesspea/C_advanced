#include <bits/stdc++.h>
using namespace std;

void printV(vector<char> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v.at(i) << endl;
    }
}

int main()
{
    vector<char> v = {'a', 'c', 'f', 'd', 'z'};

    // Updating values using indexes 3 and 2
    v[3] = 'D';
    v.at(2) = 'F';

    printV(v);

    return 0;
}
