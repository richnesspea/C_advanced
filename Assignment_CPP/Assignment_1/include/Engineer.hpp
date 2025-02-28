#ifndef __ENGINEER_H__
#define __ENGINEER_H__

#include "Employee.hpp"

class Engineer : public Employee {
private:
    std::string major;
public:
    // Constructor
    Engineer(const std::string& name = "DefaultName", uint8_t age = 17, Gender gender = Gender::Others, const std::string& major = "Default_major") : Employee(name, age, gender){
        setMajor(major);
    }  
    // Getter for major
    std::string getMajor() const;
    // Getter for role
    Work_Type getRole() const override;

    // Setter for major
    void setMajor(const std::string& major);

    // Input data
    void inputData() override;
};


#endif