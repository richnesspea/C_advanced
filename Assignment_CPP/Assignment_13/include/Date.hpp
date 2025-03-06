#ifndef __DATE_HPP__
#define __DATE_HPP__
#include <iostream>
#include "loop.hpp"


class Day
{
private:
    uint8_t day;
    uint8_t month;
    uint8_t year;

public:
    Day(uint8_t day, uint8_t month, uint8_t year);
    Day() {};
    // Getter
    uint8_t getDay() const;
    uint8_t getMonth() const;
    uint8_t getYear() const;
    // Setter
    void setDay(uint8_t day);
    void setMonth(uint8_t month);
    void setYear(uint8_t year);

    // Service functions
    void printDay(void) const;
    void addDay(void); 
};


#endif