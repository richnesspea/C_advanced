#include "Employee_manager.hpp"
#include "Employee_loop.hpp"


void Employee_manager::Add_Employee(std::vector<Employee*> &vec)
{
    Employee* emPtr;

    Work_Type work_type;
    std::cin >> work_type;
    std::cout << "the value of work_type is: " << work_type << std::endl;

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

void Employee_manager::Print_Employees(std::vector<Employee*> &vec){
    std::cout << "The Employee's information: " << std::endl;
    uint8_t i = 0;
    for(Employee* emPtr: vec){
        std::cout << "The number order is: " << i++ <<std::endl;
        std::cout << "The name: " << emPtr -> getName() <<std::endl;
        std::cout << "The age: " << emPtr -> getAge() <<std::endl;
        std::cout << "The gender: " << emPtr -> getGender() <<std::endl;
        std::cout << "The role: " << emPtr -> getRole() <<std::endl;
        std::cout << "####################" <<std::endl;
    }
}

void Employee_manager::Search_Name(std::vector<Employee*>& vec){
    std::string name_srch;
    std::cout << "Enter the employee's name" << std::endl;
    std::cin >> name_srch;
    for(Employee* emPtr: vec){
        if(emPtr->getName() == name_srch){
            std::cout << "Found employee with the info below: " << std::endl;
            std::cout << "The age: " << emPtr -> getAge() <<std::endl;
            std::cout << "The gender: " << emPtr -> getGender() <<std::endl;
            std::cout << "The role: " << emPtr -> getRole() <<std::endl;
            return;
        }
    }
    std::cout << "The employee with name:" << name_srch << " not found!"<< std::endl;
}




