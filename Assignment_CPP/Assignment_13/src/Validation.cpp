#include "Validation.hpp"



bool isLeapYear(uint8_t year)
{
    uint16_t fullYear = 1900 + year;
    return (fullYear % 4 == 0) && (fullYear % 100 != 0 || fullYear % 400 == 0);
}

uint8_t getDaysInMonth(uint8_t year, uint8_t month)
{
    static const uint8_t daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // the array is static because we want the array is allocated once
                                                                                              // and retains its value between function call
    if(month == 2 && isLeapYear(year)){
        return 29;
    }
    else {
        return daysInMonth[month];
    }
}

class BirthdayException : public std::exception {
    
};
