#ifndef __HOUSEHOLD_HPP__
#define __HOUSEHOLD_HPP__

#include "Person.hpp"
#include <vector>

class Household{
private:
    std::vector<Person*>vec;
    uint8_t numberOfMembers;
    uint8_t houseNumber;
public:
    // Parameterized constructors
    Household(uint8_t houseNumber, uint8_t numberOfMembers = 0){
        setNumberOfMembers(numberOfMembers);
        setHouseNumber(houseNumber);
    }
    
    // Getter
    uint8_t getNumberOfMembers() const;
    uint8_t getHouseNumber() const;
    const std::vector<Person*>& getMembers() const;


    // Setter
    void setNumberOfMembers(uint8_t numberOfMembers);
    void setHouseNumber(uint8_t houseNumber);
    
    // Some service functions
    void addMember(void);
    void printMembers(void) const;
    void searchMemberByID(void) const;

};


#endif
