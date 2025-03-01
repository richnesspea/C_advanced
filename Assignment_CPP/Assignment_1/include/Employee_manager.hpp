#ifndef __EMPLOYEE_MANAGER_H__
#define __EMPLOYEE_MANAGER_H__


#include "Employee.hpp"
#include "Clerk.hpp"
#include "Engineer.hpp"
#include "Worker.hpp"

class Employee_manager : public Employee{
private:

public:
    static void Add_Employee(std::vector<Employee*>& vec);
    static void Search_Name(std::vector<Employee*>& vec);
    static void Print_Employees(std::vector<Employee*> &vec);

};

#endif


