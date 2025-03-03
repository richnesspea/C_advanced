#ifndef __STREET_HPP__
#define __STREET_HPP__
#include "Household.hpp"
#include "Street_loop.hpp"
#include <unordered_map>

class Street{
private:
    std::unordered_map<uint8_t, Household *>u_map;
public:
    void addHousehold(void);
    void addPerson(void);
    void printHousehold(void) const;
    void searchHousehold(void) const;
    void searchPersonByID(void) const;
    void exitProgram(bool &flag);
};

#endif