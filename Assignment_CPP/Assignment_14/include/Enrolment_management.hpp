#ifndef __ENROLMENT_MANAGEMENT_HPP__
#define __ENROLMENT_MANAGEMENT_HPP__

#include "Student.hpp"

class Enrolment_management{
private:
    std::vector<Student *>vec_student;


public:
    void addStudent(void);
    void printStudents(void);
};


#endif