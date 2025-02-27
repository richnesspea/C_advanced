#include <iostream>
#include <vector>
#include "MyVector.hpp"

struct Person
{
    std::string name;
    int age;

    Person() = default;
    Person(std::string n, int a) : name(std::move(n)), age(a) {}

    friend std::ostream &operator<<(std::ostream &stream, const Person &other)
    {
        stream << "(" << other.name << ", " << other.age << ")";
        return stream;
    }
};

// Function to print vector elements
template <typename T>
void printVector(const Vector<T> &vec)
{
    std::cout << "Custom Vector\n";
    for (const auto &elem : vec)
    {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

template <typename T>
void printVector(const std::vector<T> &vec)
{
    std::cout << "std::vector\n";
    for (const auto &elem : vec)
    {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

int main()
{
    // Test 1: Default Constructor
    std::cout << "Test 1: Default Constructor" << std::endl;
    Vector<int> vec1;
    std::cout << "Size: " << vec1.size() << ", Capacity: " << vec1.capacity() << std::endl;

    // Test 2: Fill Constructor
    std::cout << "\nTest 2: Fill Constructor" << std::endl;
    Vector<int> vec2(5, 100); // Create vector with 5 elements initialized to 100
    printVector(vec2);
    std::cout << "Size: " << vec2.size() << ", Capacity: " << vec2.capacity() << std::endl;

    // Test 3: Copy Constructor
    std::cout << "\nTest 3: Copy Constructor" << std::endl;
    Vector<int> vec3(vec2);
    printVector(vec3);

    // Test 4: Move Constructor
    std::cout << "\nTest 4: Move Constructor" << std::endl;
    Vector<int> vec4(std::move(vec3));
    printVector(vec4);

    // Test 5: Initializer List Constructor
    std::cout << "\nTest 5: Initializer List Constructor" << std::endl;
    Vector<int> vec5{10, 20, 30, 40, 50};
    printVector(vec5);

    // Test 6: push_back()
    std::cout << "\nTest 6: push_back()" << std::endl;
    vec5.push_back(60);
    int x = 70;
    vec5.push_back(x);
    printVector(vec5);
    std::cout << "Size: " << vec5.size() << ", Capacity: " << vec5.capacity() << std::endl;

    // Test 7: pop_back()
    std::cout << "\nTest 7: pop_back()" << std::endl;
    vec5.pop_back();
    printVector(vec5);
    std::cout << "Size: " << vec5.size() << ", Capacity: " << vec5.capacity() << std::endl;

    // Test 8: insert()
    std::cout << "\nTest 8: insert()" << std::endl;
    vec5.insert(vec5.begin() + 2, 99); // Insert at index 2
    int y = 100;
    vec5.insert(vec5.end(), y);
    vec5.insert(vec5.end(), {21, 7, 2003});
    printVector(vec5);

    // Test 9: emplace_back() with Person struct
    std::cout << "\nTest 9: emplace_back() with Person struct" << std::endl;
    Vector<Person> people;
    people.emplace_back("NguyenVanA", 25);
    people.emplace_back("NguyenVanB", 30);
    people.emplace_back("NguyenVanC", 35);
    printVector(people);
    std::cout << "Size: " << people.size() << ", Capacity: " << people.capacity() << std::endl;

    // Test 10: Element Access
    std::cout << "\nTest 10: Element Access" << std::endl;
    std::cout << "Front: " << people.front() << ", Back: " << people.back() << std::endl;
    std::cout << "Element at index 1: " << people.at(1) << std::endl;

    // Test 11: resize()
    std::cout << "\nTest 11: resize()" << std::endl;
    people.resize(5, Person("Unknown", 0));
    printVector(people);
    std::cout << "Size: " << people.size() << ", Capacity: " << people.capacity() << std::endl;

    // Test 12: clear()
    std::cout << "\nTest 12: clear()" << std::endl;
    people.clear();
    std::cout << "Size after clear: " << people.size() << ", Capacity: " << people.capacity() << std::endl;

    return 0;
}
