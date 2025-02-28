#include "Employee.hpp"
#include <vector>
class Employee_manager : public Employee{
private:

public:
    void Add_Employee(std::vector<Employee*>& vec);
    void Sort_By_Name(const std::string &name);
    void Print_Employees();
    void Exit_program();


};

void Employee_Manager(void);
