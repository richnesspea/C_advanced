#ifndef __EXPERIENCE_HPP__
#define __EXPERIENCE_HPP__

#include "Employee.hpp"

class Experience : public Employee
{
private:
    uint8_t expInYear;
    std::string proSkill;

public:
    // Employee(const std::string &id, const std::string &fullname, const Day &day, const std::string &phone, const std::string &email, Employee_type employee_type);
    Experience(const std::string &id, const std::string &fullname, const Day &day, const std::string &phone, const std::string &email, Employee_type employee_type,
               uint8_t expInYear, const std::string &proSkill);
    // Getter
    uint8_t getExpInYear() const;
    std::string getProSkill() const;

    // Setter
    void setExpInYear(uint8_t expInYear);
    void setProSkill(const std::string &proSkill);

    // Show me virtual funciton
    void showMe();

};

#endif