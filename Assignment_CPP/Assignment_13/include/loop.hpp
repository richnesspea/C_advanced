#ifndef __LOOP_H__
#define __LOOP_H__
#include "Employee.hpp"
#include "Employee_manager.hpp"

std::ostream& operator<<(std::ostream& COUT, const Day& day);
std::ostream& operator<<(std::ostream& COUT, uint8_t int8_var);
std::ostream& operator<<(std::ostream& COUT, Employee_type employee_type);
std::ostream& operator<<(std::ostream& COUT, Rank rank);


std::istream& operator>>(std::istream& CIN, uint8_t &int8_var);
std::istream& operator>>(std::istream& CIN, Day& day);
std::istream& operator>>(std::istream& CIN, Employee_type& employee_type);
std::istream& operator>>(std::istream& CIN, Rank& rank);

void Employee_Manager_loop(void);

#endif