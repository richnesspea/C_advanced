#include <iostream>
using namespace std;

void safeFunction() noexcept { // Guarantees no exception
    cout << "This function will never throw an exception.\n";
}

void riskyFunction() { // Might throw an exception
    throw runtime_error("Error occurred!");
}

int main() {
    cout << "safeFunction is noexcept? " << noexcept(safeFunction()) << endl;  // ✅ true (1)
    cout << "riskyFunction is noexcept? " << noexcept(riskyFunction()) << endl; // ❌ false (0)
}
