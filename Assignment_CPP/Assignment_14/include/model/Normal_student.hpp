#ifndef __NORMAL_STUDENT_HPP__
#define __NORMAL_STUDENT_HPP__

#include "Student.hpp"

class Normal_student : public Student{
private:    
    uint8_t english_score;
    std::string entry_test_score;
public:
    Normal_student(const std::string &fullname, const Day &dob, Sex_type sex, const std::string &phone, const std::string &university_name, Graduation_type grade_level,  uint8_t english_score, const std::string &entry_test_score);

    // Getter
    uint8_t getEnglish_score() const;
    std::string getEntry_test_score() const;
    // Setter
    void setEnglish_score(uint8_t english_score);
    void setEntry_test_score(const std::string &entry_test_score);

    void showMyInfor(void);

};


#endif