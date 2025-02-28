#ifndef __EMPLOYEE_H__
#define __EMPLOYEE_H__

#include <iostream>
#include <string>
#include <cctype>
#include <vector>

enum Gender{
    Male,
    Female,
    Others,
};

enum Work_Type{
    Engineer_work,
    Clerk_work,
    Worker_work,
};

class Employee{
private:
    std::string name;
    uint8_t age;
    Gender gender;
protected:
public:
    // Constructor
    Employee(const std::string& name, uint8_t age, Gender gender){
        setName(name);
        setAge(age);
        setGender(gender);
    }
    // We don't need copy and move constructor because std::string have its own default ones.

    // Getter for name
    std::string getName() const;
    // Getter for age
    uint8_t getAge() const;
    // Getter for gender
    Gender getGender() const;

    // Setter for name
    void setName(const std::string& name);
        
    // Setter for age
    void setAge(uint8_t age);
    // Setter for gender
    void setGender(Gender gender);


    // Pure virtual function
    // Getter for role
    virtual Work_Type getRole() const = 0;
    virtual void inputData() = 0;


    
};




#endif