#ifndef __CLERK_H__
#define __CLERK_H__

#include "Employee.hpp"

class Clerk : public Employee {
private:
    std::string task;
public:
    // Constructor
    Clerk(const std::string& name, uint8_t age, Gender gender, const std::string& task) : Employee(name, age, gender){
        setTask(task);
    }  
    // Getter for major
    std::string getTask() const;
    // Setter for major
    void setTask(const std::string& task);
};


#endif