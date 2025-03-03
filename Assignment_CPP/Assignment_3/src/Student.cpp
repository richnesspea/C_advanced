#include "Student.hpp"

// Getter
uint16_t Student::getID() const {return this->id;}
std::string Student::getName() const{return this->name;}
std::string Student::getAddress() const{return this->address;}
Block Student::getBlock() const{return this->block;}
Priority Student::getPriority() const{return this->priority;}

// Setter
void Student::setID(uint16_t id){
    this->id = id;
}
void Student::setName(const std::string &name){
    this->name = name;
}
void Student::setAddress(const std::string &address){
    this->address = address;
}
void Student::setBlock(Block block){
    this->block = block;
}
void Student::setPriority(Priority priority){
    this-> priority = priority;
}