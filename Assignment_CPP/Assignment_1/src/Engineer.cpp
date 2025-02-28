#include "Engineer.hpp"
#include "Employee_loop.hpp"

// Getter for major
std::string Engineer::getMajor() const{return this->major;}
// Setter for major
void Engineer::setMajor(const std::string& major){
    this -> major = major;
}

Work_Type Engineer::getRole() const {
    return Work_Type::Engineer_work;
}

void Engineer::inputData(){
    std::string name;
    uint8_t age;
    Gender gender;
    std::string major; 

    std::cout << "Enter the name for Engineer" << std::endl;
    std::cin >> name;
    setName(name);

    std::cout << "Enter the age for Engineer" << std::endl;
    std::cin >> age;
    setAge(age);
    
    std::cout << "Enter the gender for Engineer" << std::endl;
    std::cin >> gender;
    setGender(gender);

    std::cout << "Enter the major for Engineer" << std::endl;
    std::cin >> major;
    setMajor(major);

}
