#ifndef __EMPLOYEE_MANAGER_HPP__
#define __EMPLOYEE_MANAGER_HPP__

#include "Employee.hpp"

#include "Fresher.hpp"
#include "Experience.hpp"

#include <unordered_map>

class Employee_manager {
private:
    std::unordered_map<std::string, Employee*>u_map;
public:
    // Service functions
    void addEmployee();
    void modifyEmployeeByID(void);
    void deleteEmployeeByID(void);

    void printEmployees(void) const;
    void printByEmployee_type(void) const;
    
};

#endif
