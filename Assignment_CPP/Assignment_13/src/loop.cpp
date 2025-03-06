#include "Employee.hpp"
#include <iostream>
#include "Employee_manager.hpp"
#include <limits>

std::ostream &operator<<(std::ostream &COUT, Employee_type employee_type)
{
    switch (employee_type)
    {
    case Employee_type::Experience_employee:
        COUT << "Experience";
        break;
    case Employee_type::Fresher_employee:
        COUT << "Fresher";
        break;
    case Employee_type::Intern_employee:
        COUT << "Intern";
        break;
    }
    return COUT;
}

std::ostream &operator<<(std::ostream &COUT, Rank rank)
{
    switch (rank)
    {
    case Rank::Excellent:
        COUT << "Excellent";
        break;
    case Rank::Good:
        COUT << "Good";
        break;
    case Rank::Intermediate:
        COUT << "Intermediate";
        break;
    }
    return COUT;
}



std::istream &operator>>(std::istream &CIN, Employee_type &employee_type)
{
    std::string input;

    do
    {
        std::cout << "Enter the Employee_type (Experience/Fresher/Intern): " <<std::endl;
        CIN >> input;
        if (input == "Experience")
        {
            employee_type = Employee_type::Experience_employee;
            break;
        }
        if (input == "Fresher")
        {
            employee_type = Employee_type::Fresher_employee;
            break;
        }
        if (input == "Intern")
        {
            employee_type = Employee_type::Intern_employee;
            break;
        }
    } while (true);
    return CIN;
}

std::istream &operator>>(std::istream &CIN, Rank &rank)
{
    std::string input;

    do
    {
        std::cout << "Enter the Rank (Excellent/Good/Intermediate): " <<std::endl;
        CIN >> input;
        if (input == "Excellent")
        {
            rank = Rank::Excellent;
            break;
        }
        if (input == "Good")
        {
            rank = Rank::Good;
            break;
        }
        if (input == "Intermedidate")
        {
            rank = Rank::Intermediate;
            break;
        }
    } while (true);
    return CIN;
}


std::ostream& operator<<(std::ostream& COUT, uint8_t int8_var) {
    COUT << static_cast<int>(int8_var); // Cast to int for correct display
    return COUT;
}

std::istream& operator>>(std::istream& CIN, uint8_t& int8_var) {
    int temp;
    
    if (!(CIN >> temp)) {
        std::cerr << "Invalid input. Please enter an integer.\n";
        CIN.clear();
        CIN.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return CIN;
    }

    if (temp < 0 || temp > 255) {
        std::cerr << "Value out of range. Please enter a value between 0 and 255.\n";
        CIN.setstate(std::ios::failbit);
    } else {
        int8_var = static_cast<uint8_t>(temp);
    }

    return CIN;
}


static void displayMenu() {
    std::cout << "\n===== Employee Management System =====\n";
    std::cout << "1. Add Employee\n";
    std::cout << "2. Modify Employee Information\n";
    std::cout << "3. Show All Employees\n";
    std::cout << "4. Show Employees by Type\n";
    std::cout << "5. Delete Employee by ID\n";
    std::cout << "6. Exit\n";
    std::cout << "=======================================\n";
    std::cout << "Enter your choice: ";
}



void Employee_Manager_loop(void) {
    Employee_manager manager;
    bool flag = true;
    uint8_t choice = 1;

    while (flag) {
        displayMenu();
        std::cin >> choice;

        switch (choice) {
            case 1:
                manager.addEmployee();
                break;
            case 2:
                manager.modifyEmployeeByID();
                break;
            case 3:
                manager.printEmployees();
                break;
            case 4:
                manager.printByEmployee_type();
                break;
            case 5:
                manager.deleteEmployeeByID();
                break;
            case 6:
                std::cout << "Exiting the Employee Management System.\n";
                flag = false;
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
                choice = 1;
                break;
        }
    }
}


void Employee_manager::printEmployees() const {
    if (u_map.empty()) {
        std::cout << "There are no employees to display!" << std::endl;
        return;
    }

    std::cout << "Employee List:" << std::endl;
    for (const auto &pair : u_map) {
        pair.second->showMe();
        std::cout << "---------------------------" << std::endl;
    }
}
