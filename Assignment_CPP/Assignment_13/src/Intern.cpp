#include "../include/Intern.hpp"

// Intern::Intern(const std::string &id, const std::string &fullname, const Day &day, const std::string &phone, const std::string &email,
//                Employee_type employee_type, const std::string &majors, const std::string &semester, const std::string &university_name) : Employee(id, fullname, day, phone, email, employee_type) {
//                 setMajors(majors);
//                 setSemester(semester);
//                 setUniversity_name(university_name);
//                                                                                                                                           };

std::string Intern::getMajors() const{return this->majors;}
std::string Intern::getSemester() const{return this->semester;}
std::string Intern::getUniversity_name() const{return this->university_name;}

void Intern::setMajors(const std::string &majors){this->majors = majors;}
void Intern::setSemester(const std::string &semester){this->semester = semester;}
void Intern::setUniversity_name(const std::string &university_name){this->university_name = university_name;}


