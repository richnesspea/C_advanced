#include "Household.hpp"
#include "Street_loop.hpp"

// Getter
uint8_t Household::getNumberOfMembers() const { return this->numberOfMembers; }
uint8_t Household::getHouseNumber() const { return this->houseNumber; }
const std::vector<Person*>& Household::getMembers() const { return vec; }

// Setter
void Household::setNumberOfMembers(uint8_t numberOfMembers) { this->numberOfMembers = numberOfMembers; }
void Household::setHouseNumber(uint8_t houseNumber) { this->houseNumber = houseNumber; }

// Service funcitons
// Person(const std::string &name, uint8_t age, const std::string &job, const std::string id)
void Household::addMember(void)
{
    std::string name;
    uint8_t age;
    std::string job;
    std::string id;

    std::cout << "Enter the name: " << std::endl;
    std::cin >> name;
    std::cout << "Enter the age: " << std::endl;
    std::cin >> age;
    std::cout << "Enter the id: " << std::endl;
    std::cin >> id;
    std::cout << "Enter the job: " << std::endl;
    std::cin >> job;
    Person *newPerson = new Person(name, age, job, id);
    vec.push_back(newPerson);

    this->numberOfMembers++;
}

void Household::printMembers(void) const
{
    std::cout << "The Student's information: " << std::endl;
    for (Person *ptr : vec)
    {
        std::cout << "The name: " << ptr->getName() << std::endl;
        std::cout << "The age: " << ptr->getAge() << std::endl;
        std::cout << "The job: " << ptr->getJob() << std::endl;
        std::cout << "The id: " << ptr->getID() << std::endl;
        std::cout << "####################" << std::endl;
    }
}

void Household::searchMemberByID(void) const
{
    std::string id;
    std::cout << "Enter the student's ID" << std::endl;
    std::cin >> id;
    for (Person *ptr : vec)
    {
        if (ptr->getID() == id)
        {
            std::cout << "The name: " << ptr->getName() << std::endl;
            std::cout << "The age: " << ptr->getAge() << std::endl;
            std::cout << "The job: " << ptr->getJob() << std::endl;
            std::cout << "The id: " << ptr->getID() << std::endl;
            std::cout << "####################" << std::endl;
            return;
        }
    }
    std::cout << "The person with id:" << id << " not found!" << std::endl;
};


