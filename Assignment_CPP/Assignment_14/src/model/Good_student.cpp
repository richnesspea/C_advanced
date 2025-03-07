#include "model/Good_student.hpp"

Good_student::Good_student(const std::string &fullname, const Day &dob, Sex_type sex, const std::string &phone, const std::string &university_name, Graduation_type grade_level, uint8_t gpa, const std::string &best_reward_name)
    : Student(fullname, dob, sex, phone, university_name, grade_level)
{
    setGpa(gpa);
    setBest_reward_name(best_reward_name);
}

// Getter
uint8_t Good_student::getGpa() const { return this->gpa; }
std::string Good_student::getBest_reward_name() const { return this->best_reward_name; }
// Setter
void Good_student::setGpa(uint8_t gpa) { this->gpa = gpa; }
void Good_student::setBest_reward_name(const std::string &best_reward_name) { this->best_reward_name = best_reward_name; }

void Good_student::showMyInfor(void)
{
    std::cout << "The gpa: " << this->getGpa() << std::endl;
    std::cout << "The best_reward_name: " << this->getBest_reward_name() << std::endl;
}
