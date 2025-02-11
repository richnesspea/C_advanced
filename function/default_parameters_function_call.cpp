#include <iostream>
#include <chrono>  // For measuring time

// A function that simulates an "expensive" calculation
int expensiveCalculation() {
    std::cout << "Performing expensive calculation...\n";
    int sum = 0;
    for (int i = 0; i < 100000000; ++i) {
        sum += i;
    }
    return sum;
}

// Function with default argument, passing parameters by reference
void display(const int& x, const int& y = expensiveCalculation()) {
    std::cout << "x = " << x << ", y = " << y << std::endl;
}

int main() {
    auto start = std::chrono::high_resolution_clock::now();

    std::cout << "Calling display with two arguments:\n";
    int a = 5;
    int b = 20;
    display(a, b);  // y is explicitly passed, so expensiveCalculation() is NOT called

    auto mid = std::chrono::high_resolution_clock::now();

    std::cout << "\nCalling display with one argument:\n";
    int c = 10;
    display(c);  // y is omitted, so expensiveCalculation() is called

    auto end = std::chrono::high_resolution_clock::now();

    // Measure and print execution time
    std::chrono::duration<double> time1 = mid - start;
    std::chrono::duration<double> time2 = end - mid;
    std::cout << "\nExecution time for first call (no expensive calculation): " << time1.count() << " seconds\n";
    std::cout << "Execution time for second call (with expensive calculation): " << time2.count() << " seconds\n";

    return 0;
}
