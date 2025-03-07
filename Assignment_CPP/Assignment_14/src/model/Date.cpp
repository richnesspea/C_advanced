#include "Date.hpp"

// Default constructor:
Day::Day() : day(1), month(1), year(1){}


// Parameterized constructor
Day::Day(uint8_t day, uint8_t month, uint8_t year) {
    setDay(day);
    setMonth(month);
    setYear(year);
}

// Getters
uint8_t Day::getDay() const { return day; }
uint8_t Day::getMonth() const { return month; }
uint8_t Day::getYear() const { return year; }

// Setters
void Day::setDay(uint8_t day) { this->day = day; }
void Day::setMonth(uint8_t month) { this->month = month; }
void Day::setYear(uint8_t year) { this->year = year; }

// Service functions
void Day::printDay() const {
    std::cout << "Date: " << (int)getDay() 
              << "/" << (int)getMonth() 
              << "/" << (int)getYear() 
              << std::endl;
}

void Day::addDay() {
    uint8_t day, month, year;

    std::cout << "Enter the day: ";
    std::cin >> day;
    setDay(day);

    std::cout << "Enter the month: ";
    std::cin >> month;
    setMonth(month);

    std::cout << "Enter the year: ";
    std::cin >> year;
    setYear(year);
}
