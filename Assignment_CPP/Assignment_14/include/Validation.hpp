#ifndef __VALIDATION_HPP__
#define __VALIDATION_HPP__

#include "model/Student.hpp"
#include <stdexcept>


void validateName(const std::string &name);
void validateDOB(const Day &dob);
void validatePhone(const std::string &phone);

#endif
