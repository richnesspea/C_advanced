#include "Employee.hpp"

std::string Employee::getName() const { return this -> name; }
uint8_t Employee::getAge() const { return this -> age; }
Gender Employee::getGender() const { return this -> gender; }

void Employee::setName(const std::string& name){
    if(name.empty()){
        std::cout << "Error: name can not be empty" << std::endl;
        return;
    }
    for(char i : name){
        if(!std::isalpha(i) && i != ' '){
            std::cout << "Error: name contains alphabetic characters and spaces" << std::endl;
            return;
        }
    }
    this->name = name;
}

void Employee::setAge(uint8_t age) {
    if(age < 16 || age > 70){
        std::cout << "Error: age must be between 16 and 70" << std::endl;
        return;
    }
    this->age = age;
}

void Employee::setGender(Gender gender) {
    this-> gender = gender;    
}


