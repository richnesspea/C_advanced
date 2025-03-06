#ifndef __FRESHER_HPP__
#define __FRESHER_HPP__

#include "Employee.hpp"

class Fresher : public Employee
{
private:
    Day graduation_date;
    Rank graduation_rank;
    std::string education;

public:
    // Employee(const std::string &id, const std::string &fullname, const Day &day, const std::string &phone, const std::string &email, Employee_type employee_type);

    Fresher(const std::string &id, const std::string &fullname, const Day &day, const std::string &phone, const std::string &email, Employee_type employee_type, const Day &graduation_date, Rank graduation_rank, const std::string &education);

    // Getter
    Day getGraduation_date() const;
    Rank getGraduation_rank() const;
    std::string getEducation() const;
    // Setter
    void setGraduation_date(const Day &graduation_date);
    void setGraduation_rank(Rank graduation_rank);
    void setEducation(const std::string &education);

    void showMe();
};

#endif