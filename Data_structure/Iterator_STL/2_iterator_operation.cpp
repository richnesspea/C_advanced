#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> vec = {10, 20, 30, 40, 50};

    // Declare an iterator
    vector<int>::iterator it = vec.begin();

    // ✅ 1. Dereferencing iterator (accessing and updating value)
    cout << "Original first element: " << *it << endl;
    *it = 15;  // Updating the first element
    cout << "Updated first element: " << *it << endl;

    // ✅ 2. Incrementing and Decrementing iterators
    it++;  // Move to next element
    cout << "After it++, element: " << *it << endl;
    
    ++it;  // Move again
    cout << "After ++it, element: " << *it << endl;

    it--;  // Move back
    cout << "After it--, element: " << *it << endl;

    --it;  // Move back again
    cout << "After --it, element: " << *it << endl;

    // ✅ 3. Adding/Subtracting Integer to Iterator
    it = vec.begin();  // Reset iterator to start
    it = it + 2;  // Move 2 positions forward
    cout << "After moving 2 positions forward: " << *it << endl;

    it = it - 1;  // Move 1 position back
    cout << "After moving 1 position back: " << *it << endl;

    // ✅ 4. Subtracting Two Iterators
    vector<int>::iterator it1 = vec.begin();
    vector<int>::iterator it2 = vec.end();
    cout << "Distance between begin() and end(): " << it2 - it1 << endl;

    // ✅ 5. Comparing Iterators
    if (it1 < it2)
        cout << "it1 points to an earlier element than it2" << endl;
    
    if (it1 == vec.begin())
        cout << "it1 is at the beginning of the vector" << endl;

    if (it2 > it1)
        cout << "it2 is further than it1 in the container" << endl;

    return 0;
}
