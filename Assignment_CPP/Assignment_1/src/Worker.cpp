#include "Worker.hpp"
#include "Employee_loop.hpp"

Worker_Level Worker::getLevel() const{return this -> level;}

void Worker::setLevel(Worker_Level level){
    this -> level = level;
}

Work_Type Worker::getRole() const {
    return Work_Type::Worker_work;
}

void Worker::inputData(){
    std::string name;
    uint8_t age;
    Gender gender;
    Worker_Level level; 

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
    std::cin >> level;
    setLevel(level);

}



