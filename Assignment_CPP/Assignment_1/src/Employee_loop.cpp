#include "Employee_loop.hpp"

void Employee_Manager_loop(void)
{
    bool flag = true;
    char command;
    std::vector<Employee *> Employee_ptrs; // Vector of Employee class pointers

    std::cout << "Employee Manager !!" << std::endl;

    while (flag)
    {
        std::cout << "Enter the command" << std::endl;
        std::cin >> command; //{a, s, p, e}
        switch (command)
        {
        case 'a':
            std::cout << "Let's add the new employee!!!" << std::endl;
            Employee_manager::Add_Employee(Employee_ptrs);
            break;
        case 's':
            std::cout << "Search employee in terms of name" << std::endl;
            Employee_manager::Search_Name(Employee_ptrs);
            break;
        case 'p':
            std::cout << "Print the employee list" << std::endl;
            Employee_manager::Print_Employees(Employee_ptrs);
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

std::ostream& operator<<(std::ostream& COUT, Work_Type work_type){
    switch (work_type)
    {
    case Work_Type::Clerk_work:
        COUT << "Clerk";
        break;
    case Work_Type::Engineer_work:
        COUT << "Engineer";
        break;
    case Work_Type::Worker_work:
        COUT << "Worker";
        break;
    }
    return COUT;
}

std::ostream& operator<<(std::ostream& COUT, Worker_Level work_level){
    switch (work_level)
    {
    case Worker_Level::Level1:
        COUT << "Level1";
        break;
    case Worker_Level::Level2:
        COUT << "Level2";
        break;
    case Worker_Level::Level3:
        COUT << "Level3";
        break;
    case Worker_Level::Level4:
        COUT << "Level4";
        break;
    case Worker_Level::Level5:
        COUT << "Level5";
        break;
    case Worker_Level::Level6:
        COUT << "Level6";
        break;
    case Worker_Level::Level7:
        COUT << "Level7";
        break;
    case Worker_Level::Level8:
        COUT << "Level8";
        break;
    case Worker_Level::Level9:
        COUT << "Level9";
        break;
    case Worker_Level::Level10:
        COUT << "Level10";
        break;
    }
    return COUT;
}


std::ostream &operator<<(std::ostream &COUT, Gender gender)
{
    switch (gender)
    {
    case Gender::Male:
        COUT << "Male";
        break;
    case Gender::Female:
        COUT << "Female";
        break;
    case Gender::Others:
        COUT << "Others";
        break;
    }
    return COUT;
}

std::ostream &operator<<(std::ostream &COUT, uint8_t int8_var)
{
    COUT << static_cast<int>(int8_var);
    return COUT;
}

std::istream& operator>>(std::istream& CIN, uint8_t& int8_var) {
    int temp;
    CIN >> temp;
    

    if (temp < 0 || temp > 255) {
        CIN.setstate(std::ios::failbit); 
    } else {
        int8_var = static_cast<uint8_t>(temp);
    }

    return CIN;
}





std::istream &operator>>(std::istream &CIN, Gender &gender)
{
    std::string input;

    do
    {
        std::cout << "Enter gender (Male/Female/Others): " <<std::endl;
        CIN >> input;
        if (input == "Male")
        {
            gender = Gender::Male;
            break;
        }
        if (input == "Female")
        {
            gender = Gender::Female;
            break;
        }
        if (input == "Others")
        {
            gender = Gender::Others;
            break;
        }
    } while (true);
    return CIN;
}

std::istream& operator>>(std::istream& CIN, Work_Type &work_type){
    std::string input;
    do
    {
        std::cout << "Enter work_type (Clerk/Engineer/Worker): " <<std::endl;
        CIN >> input;
        if (input == "Clerk")
        {
            work_type = Work_Type::Clerk_work;
            break;
        }
        if (input == "Engineer")
        {
            work_type = Work_Type::Engineer_work;
            break;
        }
        if (input == "Worker")
        {
            work_type = Work_Type::Worker_work;
            break;
        }
    } while (true);
    return CIN;
}

std::istream& operator>>(std::istream& CIN, Worker_Level &work_level){
    std::string input;

    do
    {
        std::cout << "Enter the worker_level (Level1/Level2/.../Level10): " <<std::endl;
        CIN >> input;
        if (input == "Level1")
        {
            work_level = Worker_Level::Level1;
            break;
        }
        if (input == "Level2")
        {
            work_level = Worker_Level::Level2;
            break;
        }
        if (input == "Level3")
        {
            work_level = Worker_Level::Level3;
            break;
        }
        if (input == "Level4")
        {
            work_level = Worker_Level::Level4;
            break;
        }
        if (input == "Level5")
        {
            work_level = Worker_Level::Level5;
            break;
        }
        if (input == "Level6")
        {
            work_level = Worker_Level::Level6;
            break;
        }
        if (input == "Level7")
        {
            work_level = Worker_Level::Level7;
            break;
        }
        if (input == "Level8")
        {
            work_level = Worker_Level::Level8;
            break;
        }
        if (input == "Level9")
        {
            work_level = Worker_Level::Level9;
            break;
        }
        if (input == "Level10")
        {
            work_level = Worker_Level::Level10;
            break;
        }
    } while (true);
    return CIN;

}
