#include "Enrolment_loop.hpp"

std::ostream &operator<<(std::ostream &COUT, Block block)
{
    switch (block)
    {
    case Block::Block_A:
        COUT << "Block_A";
        break;
    case Block::Block_B:
        COUT << "Block_B";
        break;
    case Block::Block_C:
        COUT << "Block_C";
        break;
    }
    return COUT;
}

// std::ostream &operator<<(std::ostream &COUT, uint16_t uint16_var)
// {
//     COUT << static_cast<int>(uint16_var);
//     return COUT;
// }

std::ostream &operator<<(std::ostream &COUT, Priority priority)
{
    switch (priority)
    {
    case Priority::Level1:
        COUT << "Level1";
        break;
    case Priority::Level2:
        COUT << "Level2";
        break;
    case Priority::Level3:
        COUT << "Level3";
        break;
    }
    return COUT;
}

std::istream &operator>>(std::istream &CIN, Block &block)
{
    std::string input;

    do
    {
        std::cout << "Enter the block (Block_A/ Block_B/ Block_C)" << std::endl;
        CIN >> input;
        if (input == "Block_A")
        {
            block = Block::Block_A;
            break;
        }
        if (input == "Block_B")
        {
            block = Block::Block_B;
            break;
        }
        if (input == "Block_C")
        {
            block = Block::Block_C;
            break;
        }
    } while (true);
    return CIN;
}

// std::istream &operator>>(std::istream &CIN, uint16_t &uint16_var)
// {
//     int temp;
//     CIN >> temp;

//     if (temp < 0 || temp > 65535)
//     {
//         CIN.setstate(std::ios::failbit);
//     }
//     else
//     {
//         uint16_var = static_cast<uint16_t>(temp);
//     }

//     return CIN;
// }

std::istream &operator>>(std::istream &CIN, Priority &priority)
{
    std::string input;

    do
    {
        std::cout << "Enter the priority (Level1/ Level2/ Level3)" << std::endl;
        CIN >> input;
        if (input == "Level1")
        {
            priority = Priority::Level1;
            break;
        }
        if (input == "Level2")
        {
            priority = Priority::Level2;
            break;
        }
        if (input == "Level3")
        {
            priority = Priority::Level3;
            break;
        }
    } while (true);
    return CIN;
}

void Enrolment_loop(void)
{
    bool flag = true;
    char command;
    Enrolment enrolment1;

    std::cout << "Student Enrolment !!!" << std::endl;
    std::cout << "#####################" << std::endl;
    
    while (flag)
    {
        std::cout << "1. Add new student. " << std::endl;
        std::cout << "2. Print students. " << std::endl;
        std::cout << "3. Search ID." << std::endl;
        std::cout << "4. Exit the program. " << std::endl;
        std::cout << "Enter the command (1-4): " << std::endl;
        std::cin >> command;
        switch (command)
        {
        case '1':
            std::cout << "Let's add new student!: " << std::endl;
            enrolment1.addStudent();
            break;
        case '2':
            std::cout << "Print the student list: " << std::endl;
            enrolment1.printStudents();
            break;
        case '3':
            std::cout << "Search the student by ID: " << std::endl;
            enrolment1.searchID();
            break;
        case '4':
            std::cout << "Exit the program: " << std::endl;
            enrolment1.exitProgram(flag);
            break;
        default:
            std::cout << "Invalid Command, Re-enter the command" << std::endl;
            break;
        }
    }
}
