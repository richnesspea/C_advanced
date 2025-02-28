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
    void Sort_By_Name(const std::string &name);
    void Print_Employees();
    void Exit_program();


};

#endif


