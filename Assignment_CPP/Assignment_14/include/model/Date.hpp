#ifndef __DATE_HPP__
#define __DATE_HPP__

#include <iostream>

class Day {
private:
    uint8_t day;
    uint8_t month;
    uint8_t year;

public:
    // Default constructor
    Day(); 

    // Parameterized constructor
    Day(uint8_t day, uint8_t month, uint8_t year);

    // Getters
    uint8_t getDay() const;
    uint8_t getMonth() const;
    uint8_t getYear() const;

    // Setters
    void setDay(uint8_t day);
    void setMonth(uint8_t month);
    void setYear(uint8_t year);

    // Service functions
    void printDay() const;
    void addDay(); 
};

#endif
