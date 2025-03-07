#include "model/Normal_student.hpp"

Normal_student::Normal_student(const std::string &fullname, const Day &dob, Sex_type sex, const std::string &phone, const std::string &university_name, Graduation_type grade_level, uint8_t english_score, const std::string &entry_test_score)
                : Student(fullname, dob, sex, phone, university_name, grade_level)
{
    setEnglish_score(english_score);
    setEntry_test_score(entry_test_score);
}

// Getter
uint8_t Normal_student::getEnglish_score() const{return this->english_score;}
std::string Normal_student::getEntry_test_score() const{return this->entry_test_score;}
// Setter
void Normal_student::setEnglish_score(uint8_t english_score){this->english_score = english_score;}
void Normal_student::setEntry_test_score(const std::string &entry_test_score){this->entry_test_score = entry_test_score;}

void Normal_student::showMyInfor(void){
    this->showStudent();
    std::cout << "The english_score: " << this->getEnglish_score() << std::endl;
    std::cout << "The entry_test_score: " << this->getEntry_test_score() << std::endl;
}
