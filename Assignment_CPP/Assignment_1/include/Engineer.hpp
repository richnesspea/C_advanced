#ifndef __ENGINEER_H__
#define __ENGINEER_H__

#include "Employee.hpp"

class Engineer : public Employee {
private:
    std::string major;
public:
    // Constructor
    Engineer(const std::string& name, uint8_t age, Gender gender, const std::string& major) : Employee(name, age, gender){
        setMajor(major);
    }  
    // Getter for major
    std::string getMajor() const;
    // Setter for major
    void setMajor(const std::string& major);
};


#endif