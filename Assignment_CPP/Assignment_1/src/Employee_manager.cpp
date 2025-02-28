#include "Employee_manager.hpp"
#include "Employee_loop.hpp"




void Employee_manager::Add_Employee(std::vector<Employee*> &vec)
{
    Employee* emPtr;

    Work_Type work_type;
    std::cin >> work_type;

    switch (work_type){
        case Work_Type::Clerk_work:
            emPtr = new Clerk(); 
            emPtr->inputData();
            vec.push_back(emPtr);
            return;
        case Work_Type::Engineer_work:
            emPtr = new Engineer(); 
            emPtr->inputData();
            vec.push_back(emPtr);
            return;
        case Work_Type::Worker_work:
            emPtr = new Worker(); 
            emPtr->inputData();
            vec.push_back(emPtr);
            return;
        default:
            return;
    }
}

