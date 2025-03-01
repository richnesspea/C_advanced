#ifndef __EMPLOYEE_LOOP_H__
#define __EMPLOYEE_LOOP_H__
#include "Employee.hpp"
#include "Employee_manager.hpp"

std::ostream& operator<<(std::ostream& COUT, Gender gender);
std::ostream& operator<<(std::ostream& COUT, uint8_t int8_var);
std::ostream& operator<<(std::ostream& COUT, Work_Type work_type);
std::ostream& operator<<(std::ostream& COUT, Worker_Level work_level);

std::istream& operator>>(std::istream& CIN, Gender &gender);
std::istream& operator>>(std::istream& CIN, uint8_t &int8_var);
std::istream& operator>>(std::istream& CIN, Work_Type &work_type);
std::istream& operator>>(std::istream& CIN, Worker_Level &work_type);

void Employee_Manager_loop(void);

#endif