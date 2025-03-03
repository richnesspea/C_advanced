#include "Street.hpp"
#include "Street_loop.hpp"

void Street::addHousehold(void)
{
    uint8_t houseNumber;
    std::cout << "Enter the house number:" << std::endl;
    std::cin >> houseNumber;
    if (u_map.find(houseNumber) == u_map.end())
    {
        Household *newHousehold = new Household(houseNumber);
        u_map[houseNumber] = newHousehold; // add the pointer to the value of map
        std::cout << "Successfully add new household!" << std::endl;
    }
    else
    {
        std::cout << "Failed to add new household!" << std::endl;
    }
}

void Street::addPerson(void)
{
    std::cout << "Enter the ID of the new member: " << std::endl;
    std::string id;
    std::cin >> id;

    if (u_map.empty())
    {
        std::cout << "There is no household!!! " << std::endl;
        return;
    }

    for (const auto &i : u_map)
    {
        for (Person *ptr : i.second->getMembers())
        {
            if (ptr->getID() == id)
            {
                std::cout << "The ID: " << id << " already exists!" << std::endl;
                return; 
            }
        }
    }


    uint8_t houseNumber;
    std::cout << "Enter the house number to add a new person: " << std::endl;
    std::cin >> houseNumber;

    auto i = u_map.find(houseNumber);
    if (i != u_map.end())
    {
        i->second->addMember();
        std::cout << "The member with ID: " << id << " has been added to house number " << houseNumber << std::endl;
    }
    else
    {
        std::cout << "Household not found!" << std::endl;
    }
}
void Street::printHousehold(void) const
{
    if (u_map.empty())
    {
        std::cout << "There is no household!!! " << std::endl;
    }
    else
    {
        for (const auto &i : u_map) // i is a reference to std::pair
        {
            std::cout << "The house number is: " << i.second->getHouseNumber() << std::endl;
            std::cout << "The number of members is: " << i.second->getNumberOfMembers() << std::endl;
            std::cout << "The list of members: " << std::endl;
            i.second->printMembers();
        }
    }
}
void Street::searchHousehold(void) const
{
    uint8_t houseNumber;
    std::cout << "Enter the house number to add new person! " << std::endl;
    std::cin >> houseNumber;
    // std::unordered_map<uint8_t, Household*>::iterator i = u_map.find(houseNumber);
    auto i = u_map.find(houseNumber); // i is an iterator, which works like a pointer
    if (i == u_map.end())
    {
        std::cout << "Can't find the household" << std::endl;
    }
    else
    {
        std::cout << "The house hould with house number: " << houseNumber << std::endl;
        std::cout << "The house number is: " << i->second->getHouseNumber() << std::endl;
        std::cout << "The number of members is: " << i->second->getNumberOfMembers() << std::endl;
        std::cout << "The list of members: " << std::endl;
        i->second->printMembers();
    }
}
void Street::searchPersonByID(void) const
{
    std::string id;
    std::cin >> id;
    if (u_map.empty())
    {
        std::cout << "There is no household!!! " << std::endl;
    }
    else
    {
        for (const auto &i : u_map) // i is a reference to std::pair
        {
            for (Person *ptr : i.second->getMembers())
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
        }
    }
}

void Street::exitProgram(bool &flag)
{
    flag = false;
}