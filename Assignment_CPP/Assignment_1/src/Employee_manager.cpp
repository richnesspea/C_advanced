#include "Employee_manager.hpp"

void Employee_manager::Add_Employee(std::vector<Employee*>& vec){
    std::string type_of_employee;
    std::cin >> type_of_employee;

    
}









void Employee_Manager(void){
    bool flag = true;
    char command;
    std::vector<Employee*>Employee_ptr; //Vector of Employee class pointers

    std::cout << "Employee Manager !!" << std::endl;
    
    while(flag){
        std::cout << "Enter the command" << std::endl;
        std::cin >> command; //{a, s, p, e}
        switch(command){
            case 'a':
                std::cout << "addEmployee" << std::endl;
                break;
            case 's':
                std::cout << "searchEmployeeByName" << std::endl;
                break;
            case 'p':
                std::cout << "printEmployees" << std::endl;
                break;
            case 'e':
                std::cout << "exitProgram" << std::endl;
                flag = false;
                break;
            default:
                std::cout << "Invalid Command, Re-enter the command" << std::endl;
                break;
        }
    }
}