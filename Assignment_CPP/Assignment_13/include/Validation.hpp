#ifndef __VALIDATION_HPP__
#define __VALIDATION_HPP__

#include "Employee.hpp"
#include <stdexcept>


void validateBirthday(const Day &date);
void validatePhone(const std::string &phone);
void validateEmail(const std::string &email);
void validateName(const std::string &name);


#endif
