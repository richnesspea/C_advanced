#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int count = 0;
    std::vector<int> vec = {1, 2, 3, 4, 5};

    std::for_each(vec.begin(), vec.end(), [count](int elem) mutable {
        std::cout << "Element: " << ++count << std::endl;
    });

    std::cout << "Final count: " << count << std::endl;  // Output: Final count: 0
}
