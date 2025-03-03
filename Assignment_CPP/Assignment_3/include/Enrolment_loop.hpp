#ifndef __ENROLMENT_LOOP_H__
#define __ENROLMENT_LOOP_H__
#include "Student.hpp"
#include "Enrolment.hpp"

std::ostream& operator<<(std::ostream& COUT, Block block);
// std::ostream& operator<<(std::ostream& COUT, uint16_t uint16t_var);
std::ostream& operator<<(std::ostream& COUT, Priority priority);

std::istream& operator>>(std::istream& CIN, Block &block);
// std::istream& operator>>(std::istream& CIN, uint16_t &uint16_var);
std::istream& operator>>(std::istream& CIN, Priority &priority);

void Enrolment_loop(void);

#endif

