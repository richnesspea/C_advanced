#include "Experience.hpp"

Experience::Experience(const std::string &id, const std::string &fullname, const Day &day, const std::string &phone, const std::string &email, Employee_type employee_type,
                       uint8_t expInYear, const std::string &proSkill) : Employee(id, fullname, day, phone, email, employee_type)
{
    setExpInYear(expInYear);
    setProSkill(proSkill);
}

// Getter
uint8_t Experience::getExpInYear() const{return this->expInYear;}
std::string Experience::getProSkill() const{return this->proSkill;}

// Setter
void Experience::setExpInYear(uint8_t expInYear){this->expInYear = expInYear;}
void Experience::setProSkill(const std::string &proSkill){this->proSkill = proSkill;}

void Experience::showMe(){
    this->showInfo();
    std::cout << "The experience in years: " << this->getExpInYear() << std::endl;
    std::cout << "The professional skill: " << this->getProSkill() << std::endl;    
    std::cout << "Certificates of Experience: " << std::endl;
    this->printCertificates();
}
