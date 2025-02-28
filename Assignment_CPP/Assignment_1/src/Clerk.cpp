#include "Clerk.hpp"

// Getter for major
std::string Clerk::getTask() const{return this->task;}


// Setter for major
void Clerk::setTask(const std::string& task){
    this -> task = task;
}

std::string Clerk::getRole() const {
    return "Clerk";
}

void Clerk::inputData(){
    std::string name;
    uint8_t age;
    std::string gender;
    std::string task;

    std::cout << "Enter the name for Clerk" << std::endl;
    std::cin >> name;
    setName(name);

    std::cout << "Enter the age for Clerk" << std::endl;
    std::cin >> age;
    setAge(age);
    
    std::cout << "Enter the gender for Clerk" << std::endl;
    std::cin >> gender;
    setGender(name);

    std::cout << "Enter the name for Clerk" << std::endl;
    std::cin >> name;
    setName(name);

}
