#include "Person.hpp"

// Getter
std::string Person::getID() const { return this->id; }
std::string Person::getName() const { return this->name; }
std::string Person::getJob() const { return this->job; }
uint8_t Person::getAge() const { return this->age; }

// Setter
void Person::setID(const std::string &id){this->id = id;}
void Person::setName(const std::string &name){this->name = name;}
void Person::setJob(const std::string &job){this->job = job;}
void Person::setAge(uint8_t age){this->age = age;}