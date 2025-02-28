#ifndef __EMPLOYEE_H__
#define __EMPLOYEE_H__

#include <iostream>
#include <string>
#include <cctype>

enum Gender{
    Male,
    Female,
    Others,
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
    void setGender(const std::string &gender);

    // Pure virtual function
    // Getter for role
    virtual std::string getRole() const = 0;
    virtual void inputData() = 0;


    // << overloading as enum is not default with << operator, using operator overloading and friend function
    // friend std::ostream& operator<<(std::ostream& COUT, Gender gender);
    // friend std::ostream& operator<<(std::ostream& COUT, uint8_t int8_var);
    
};

std::ostream& operator<<(std::ostream& COUT, Gender gender);
std::ostream& operator<<(std::ostream& COUT, uint8_t int8_var);
std::ostream& operator>>(std::ostream& CIN, Gender gender);


#endif