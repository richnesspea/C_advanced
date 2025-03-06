#include "Date.hpp"

// Definition of class Birthday
Day::Day(uint8_t day, uint8_t month, uint8_t year)
{
    setDay(day);
    setMonth(month);
    setYear(year);
};

uint8_t Day::getDay() const { return this->day; }
uint8_t Day::getMonth() const { return this->month; }
uint8_t Day::getYear() const { return this->year; }

void Day::setDay(uint8_t day) { this->day = day; }
void Day::setMonth(uint8_t month) { this->month = month; }
void Day::setYear(uint8_t year) { this->year = year; }

void Day::printDay(void) const{
    std::cout << "The info of day: " << std::endl;
    std::cout << "The day: " << this ->getDay();
    std::cout << "The month: " << this ->getMonth();
    std::cout << "The year: " << this ->getYear();
}

void Day::addDay(void) {
    uint8_t day, month, year;

    std::cout << "Enter the day: ";
    std::cin >> day;
    this->setDay(day);

    std::cout << "Enter the month: ";
    std::cin >> month;
    this->setMonth(month);

    std::cout << "Enter the year: ";
    std::cin >> year;
    this->setYear(year);

}



