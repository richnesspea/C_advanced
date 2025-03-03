#ifndef __ENROLMENT_H__
#define __ENROLMENT_H__

#include "Student.hpp"

class Enrolment{
private:
    std::vector<Student*> vec;
public:
    void addStudent(void);
    void printStudents(void) const;
    void searchID(void) const;
    void exitProgram(bool &flag);

};




#endif