#ifndef __INTERN_HPP__
#define __INTERN_HPP__

#include "Employee.hpp"

class Intern : public Employee
{
private:
    std::string majors;
    std::string semester;
    std::string university_name;

public:
    // Employee(const std::string &id, const std::string &fullname, const Day &day, const std::string &phone, const std::string &email, Employee_type employee_type);
    Intern(const std::string &id, const std::string &fullname, const Day &day, const std::string &phone, const std::string &email,
           Employee_type employee_type, const std::string &majors, const std::string &semester, const std::string &university_name);

    
    std::string getMajors() const;
    std::string getSemester() const;
    std::string getUniversity_name() const;

    void setMajors(const std::string &majors);
    void setSemester(const std::string &semester);
    void setUniversity_name(const std::string &University_name);

    void showMe();
};

#endif