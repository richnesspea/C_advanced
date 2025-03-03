#include "Enrolment.hpp"
#include "Enrolment_loop.hpp"

// Student(uint16_t id, const std::string &name, const std::string &address, Block block, Priority priority)
void Enrolment::addStudent(void)
{
    uint16_t id;
    std::string name;
    std::string address;
    Block block;
    Priority priority;

    std::cout << "Enter the id: " << std::endl;
    std::cin >> id;
    std::cout << "Enter the name: " << std::endl;
    std::cin >> name;
    std::cout << "Enter the address: " << std::endl;
    std::cin >> address;
    std::cout << "Enter the block: " << std::endl;
    std::cin >> block;
    std::cout << "Enter the priority: " << std::endl;
    std::cin >> priority;

    Student *newStudent = new Student(id, name, address, block, priority);
    vec.push_back(newStudent);
}

void Enrolment::printStudents(void) const
{
    std::cout << "The Student's information: " << std::endl;
    for (Student *ptr : vec)
    {
        std::cout << "The ID is: " << ptr->getID() << std::endl;
        std::cout << "The name: " << ptr->getName() << std::endl;
        std::cout << "The address: " << ptr->getAddress() << std::endl;
        std::cout << "The block: " << ptr->getBlock() << std::endl;
        std::cout << "The priority: " << ptr->getPriority() << std::endl;
        std::cout << "####################" << std::endl;
    }
}

void Enrolment::searchID(void) const
{
    uint16_t id;
    std::cout << "Enter the student's ID" << std::endl;
    std::cin >> id;
    for (Student *ptr : vec)
    {
        if (ptr->getID() == id)
        {
            std::cout << "The ID is: " << ptr->getID() << std::endl;
            std::cout << "The name: " << ptr->getName() << std::endl;
            std::cout << "The address: " << ptr->getAddress() << std::endl;
            std::cout << "The block: " << ptr->getBlock() << std::endl;
            std::cout << "The priority: " << ptr->getPriority() << std::endl;
            return;
        }
    }
    std::cout << "The student with id:" << id << " not found!" << std::endl;
};

void Enrolment::exitProgram(bool &flag){
    flag = false;
}


