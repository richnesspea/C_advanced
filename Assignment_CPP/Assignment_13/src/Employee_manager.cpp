#include "Employee_manager.hpp"
#include "../include/Intern.hpp"
#include "loop.hpp"

void Employee_manager::addEmployee(void)
{
    std::string employeeID;
    std::string fullname;
    std::string phone;
    std::string email;
    Employee_type employee_type;
    uint8_t day, month, year;

    std::cout << "Enter the employee ID: " << std::endl;
    std::cin >> employeeID;
    if (u_map.find(employeeID) == u_map.end())
    {
        std::cout << "Enter the Employee birth_day: " << std::endl;
        std::cin >> day;
        std::cout << "Enter the Employee birth_month: " << std::endl;
        std::cin >> month;
        std::cout << "Enter the Employee birth_year: " << std::endl;
        std::cin >> year;

        Day birthday(day, month, year);

        std::cout << "Enter the employee type: " << std::endl;
        std::cin >> employee_type;

        // Intern
        std::string majors;
        std::string semester;
        std::string university_name;

        switch (employee_type)
        {

        case Employee_type::Experience:

            break;
        case Employee_type::Fresher:
            break;
        case Employee_type::Intern:
            // Employee* newEmp = new Intern(employeeID, fullname, birthday, phone, email, employee_type, majors, semester, university_name);

            break;
        default:
            std::cout << "Invalid Employee type!!!! " << std::endl;
        }

        // Add the ceritificates of employees
        {
            Employee *internEmp = new Intern(employeeID, fullname, birthday, phone, email, employee_type, majors, semester, university_name);
            internEmp->addCertificate();
            u_map[employeeID] = internEmp;
        }
        std::cout << "Successfully add new employee!" << std::endl;
    }
    else
    {
        std::cout << "Failed to add new household!" << std::endl;
    }
}
