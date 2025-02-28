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

void Employee::setGender(const std::string &gender){
    std::cout << "Enter: (Male)/ (Female)/ (Others)" << std::endl;
    if(gender == "Male"){
        this -> gender = Gender::Male;
        return;
    }
    if(gender == "Female"){
        this -> gender = Gender::Female;
        return;
    }
    if(gender == "Others"){
        this -> gender = Gender::Others;
        return;
    }
}



std::ostream& operator<<(std::ostream& COUT, Gender gender){
    switch(gender){
        case Gender::Male: 
            COUT << "Male"; 
            break;
        case Gender::Female: 
            COUT << "Female"; 
            break;
        case Gender::Others: 
            COUT << "Others"; 
            break;
    }   
    return COUT;
}



std::ostream& operator<<(std::ostream& COUT, uint8_t int8_var){
    COUT << static_cast<int>(int8_var);
    return COUT;
}


