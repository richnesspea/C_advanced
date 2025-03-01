#include "Clerk.hpp"
#include "Employee_loop.hpp"
// Getter for major
std::string Clerk::getTask() const{return this->task;}


// Setter for major
void Clerk::setTask(const std::string& task){
    this -> task = task;
}

Work_Type Clerk::getRole() const {
    return Work_Type::Clerk_work;
}

void Clerk::inputData(){
    std::string name;
    uint8_t age;
    Gender gender;
    std::string task;

    std::cout << "Enter the name for Clerk" << std::endl;
    std::cin >> name;
    setName(name);

    std::cout << "Enter the age for Clerk" << std::endl;
    std::cin >> age;
    setAge(age);

    
    std::cout << "Enter the gender for Clerk" << std::endl;
    std::cin >> gender;
    setGender(gender);

    std::cout << "Enter the task for Clerk" << std::endl;
    std::cin >> task;
    setTask(task);

}
