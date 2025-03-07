#include "model/Student.hpp"

// Parameterized constructor
Student::Student(const std::string &fullname, const Day &dob, Sex_type sex, const std::string &phone, const std::string &university_name, Graduation_type grade_level){
    setFullname(fullname);
    setDob(dob);
    setSex(sex);
    setPhone(phone);
    setUniversity_name(university_name);
    setGrade_level(grade_level);
}

// Getter
std::string Student::getFullname() const{return this->fullname;}
Day Student::getDob() const{return this->dob;}
Sex_type Student::getSex() const{return this->sex;}
std::string Student::getPhone() const{return this->phone;}
std::string Student::getUniversity_name() const{return this->university_name;}
Graduation_type Student::getGrade_level() const{return this->grade_level;}

// Setter

void Student::setFullname(const std::string &fullname){this->fullname = fullname;}
void Student::setDob(const Day &dob){this->dob = dob;}
void Student::setSex(Sex_type sex){this->sex =sex;}
void Student::setPhone(const std::string &phone){this->phone = phone;}
void Student::setUniversity_name(const std::string &university_name){this->university_name = university_name;}
void Student::setGrade_level(Graduation_type grade_level){this->grade_level = grade_level;}

void Student::showStudent(void){
    std::cout << " ======= The information of Student =======" << std::endl;
    std::cout << "The fullname: " << this->getFullname() << std::endl;
    std::cout << "The dob: "; 
    this->dob.printDay();
    std::cout << "The sex: " << this->getSex() << std::endl;
    std::cout << "The phone: " << this->getPhone() << std::endl;
    std::cout << "The university_name: " << this->getUniversity_name() << std::endl;
    std::cout << "The grade_level: " << this->getGrade_level() << std::endl;
}

