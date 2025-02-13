#include<iostream>
#include<string>

class Person {
    public:
    
    std::string name;
    int age;
    
    void introduce(){
        std::cout << "Hello world!" << std::endl;
    }
};

int main(){
    Person person1;

    //Accessing data members
    person1.name = "DoQuangLong";
    person1.age = 23;
    
    //Call the introduce member method of Person class
    person1.introduce();
    
    return 0;
}