#ifndef __CLERK_H__
#define __CLERK_H__

#include "Employee.hpp"

class Clerk : public Employee {
private:
    std::string task;
public:

    Clerk(const std::string& name = "DefaultName", uint8_t age = 17, Gender gender = Gender::Others, const std::string& task = "Default_task") : Employee(name, age, gender){
        setTask(task);
    }  
    // Getter for major
    std::string getTask() const;

    // Setter for major
    void setTask(const std::string& task);


    // Getter for role
    Work_Type getRole() const override;
    
    // Input data
    void inputData() override;
};


#endif