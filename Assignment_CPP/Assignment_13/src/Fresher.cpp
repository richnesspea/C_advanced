#include "Fresher.hpp"

// Constructor
Fresher::Fresher(const std::string &id,
                 const std::string &fullname,
                 const Day &day,
                 const std::string &phone,
                 const std::string &email,
                 Employee_type employee_type,
                 const Day &graduation_date,
                 Rank graduation_rank,
                 const std::string &education)
    : Employee(id, fullname, day, phone, email, employee_type),
      graduation_date(graduation_date),
      graduation_rank(graduation_rank),
      education(education)
{
    setGraduation_date(graduation_date);
    setGraduation_rank(graduation_rank);
    setEducation(education);
}

// Getters
Day Fresher::getGraduation_date() const
{
    return graduation_date;
}

Rank Fresher::getGraduation_rank() const
{
    return graduation_rank;
}

std::string Fresher::getEducation() const
{
    return education;
}

// Setters
void Fresher::setGraduation_date(const Day &graduation_date)
{
    this->graduation_date = graduation_date;
}

void Fresher::setGraduation_rank(Rank graduation_rank)
{
    this->graduation_rank = graduation_rank;
}

void Fresher::setEducation(const std::string &education)
{
    this->education = education;
}

void Fresher::showMe(){
    this->showInfo();
    std::cout << "The graduation date: " << std::endl;
    this->getGraduation_date().printDay();
    std::cout << "The graduation rank: " << this->getGraduation_rank() << std::endl;
    std::cout << "Certificates of Fresher: " << std::endl;
    this->printCertificates();
}

