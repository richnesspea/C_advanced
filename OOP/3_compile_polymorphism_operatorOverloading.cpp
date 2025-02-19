#include <iostream>
using namespace std;

class Person {
public:
    string name;
    int age;

    // Constructor
    Person(string Name, int Age) : name(Name), age(Age) {}

    // Overload the + operator (Binary Operator Overloading)
    Person operator+(const Person& other) const {
        return Person(this->name + "&" + other.name, this->age + other.age);
    }

    // Overload the << operator for output stream
    friend ostream& operator<<(ostream& COUT, const Person& PERSON);
};

// Overload << operator (Friend function)
ostream& operator<<(ostream& COUT, const Person& PERSON) {
    COUT << "Name: " << PERSON.name << endl;
    COUT << "Age: " << PERSON.age << endl;
    return COUT;
}

int main() {
    Person person1("LongDoQuang", 22);
    Person person2("HoaDangThi", 23);

    cout << "Person 1: " << endl << person1 << endl;
    cout << "Person 2: " << endl << person2 << endl;

    // Operator overloading (+) for Person
    Person person3 = person1 + person2; 
    cout << "Combined Person: " << endl << person3 << endl;

    return 0;
}
