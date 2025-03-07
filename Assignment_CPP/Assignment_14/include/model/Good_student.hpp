#ifndef __GOOD_STUDENT_HPP__
#define __GOOD_STUDENT_HPP__

#include "Student.hpp"

class Good_student : public Student
{
private:
    uint8_t gpa;
    std::string best_reward_name;

public:
    Good_student(const std::string &fullname, const Day &dob, Sex_type sex, const std::string &phone, const std::string &university_name, Graduation_type grade_level, uint8_t gpa, const std::string &best_reward_name);

    // Getter
    uint8_t getGpa() const;
    std::string getBest_reward_name() const;
    // Setter
    void setGpa(uint8_t gpa);
    void setBest_reward_name(const std::string &best_reward_name);

    void showMyInfor(void);
};

#endif