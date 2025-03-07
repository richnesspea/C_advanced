#ifndef __STUDENT_HPP__
#define __STUDENT_HPP__

#include "Date.hpp"
#include <vector>

enum Student_type{
    GOOD_STUDENT,
    NORMAL_STUDENT,
};

enum Sex_type{
    MEN,
    WOMEN,
    OTHERS,
};

enum Graduation_type{
    EXCELLENT,
    GOOD,
    INTERMEDIATE,
};

class Student{
private:
    std::string fullname;
    Day dob;
    Sex_type sex;
    std::string phone;
    std::string university_name;
    Graduation_type grade_level;

public:
    // Parameterized constructor
    Student(const std::string &fullname, const Day &dob, Sex_type sex, const std::string &phone, const std::string &university_name, Graduation_type grade_level);
    // Getter
    std::string getFullname() const;
    Day getDob() const;
    Sex_type getSex() const;
    std::string getPhone() const;
    std::string getUniversity_name() const;
    Graduation_type getGrade_level() const;

    // Setter

    void setFullname(const std::string &fullname);
    void setDob(const Day &dob);
    void setSex(Sex_type sex);
    void setPhone(const std::string &phone);
    void setUniversity_name(const std::string &university_name);
    void setGrade_level(Graduation_type grade_level);
    void showStudent(void);
    virtual void showMyInfor(void) = 0;
};



#endif
