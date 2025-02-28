#include "Clerk.hpp"

// Getter for major
std::string Clerk::getTask() const{return this->task;}
// Setter for major
void Clerk::setTask(const std::string& task){
    this -> task = task;
}

