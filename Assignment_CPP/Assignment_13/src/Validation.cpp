#include "Validation.hpp"
#include <regex>
#include <iostream>
#include <stdexcept>

// Leap year check
bool isLeapYear(uint8_t year) {
    uint16_t fullYear = 1900 + year;
    return (fullYear % 4 == 0) && (fullYear % 100 != 0 || fullYear % 400 == 0);
}

// Get the days in a month considering leap years
uint8_t getDaysInMonth(uint8_t year, uint8_t month) {
    static const uint8_t daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && isLeapYear(year)) {
        return 29;
    } else if (month >= 1 && month <= 12) {
        return daysInMonth[month];
    } else {
        throw std::invalid_argument("Invalid month");
    }
}

// Exception classes
class BirthdayException : public std::exception {
public:
    const char *what() const noexcept override {
        return "Invalid birthday date!";
    }
};

class PhoneException : public std::exception {
public:
    const char *what() const noexcept override {
        return "Invalid phone number! Phone number must be 10-15 digits.";
    }
};

class EmailException : public std::exception {
public:
    const char *what() const noexcept override {
        return "Invalid email format!";
    }
};

class NameException : public std::exception {
public:
    const char *what() const noexcept override {
        return "Invalid name! Name must only contain alphabetic characters and spaces.";
    }
};

// Validate birthday date
void validateBirthday(const Day &date) {
    if (date.getMonth() < 1 || date.getMonth() > 12) {
        throw BirthdayException();
    }

    uint8_t maxDays = getDaysInMonth(date.getYear(), date.getMonth());
    if (date.getDay() < 1 || date.getDay() > maxDays) {
        throw BirthdayException();
    }
}

// Validate phone number (10-15 digits, allowing only digits)
void validatePhone(const std::string &phone) {
    std::regex phonePattern("^\\d{10,15}$");
    if (!std::regex_match(phone, phonePattern)) {
        throw PhoneException();
    }
}

// Validate email format
void validateEmail(const std::string &email) {
    std::regex emailPattern(R"(([\w\.-]+)@([\w\.-]+)\.([a-zA-Z]{2,}))");
    if (!std::regex_match(email, emailPattern)) {
        throw EmailException();
    }
}

// Validate name (only alphabets and spaces, between 1 and 50 characters)
void validateName(const std::string &name) {
    std::regex namePattern("^[A-Za-z ]{1,50}$");
    if (!std::regex_match(name, namePattern)) {
        throw NameException();
    }
}
