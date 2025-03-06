#include "Employee.hpp"
#include "loop.hpp"

// Definition of class Employee

Employee::Employee(const std::string &id, const std::string &fullname, const Day &day, const std::string &phone, const std::string &email, Employee_type employee_type)
{
    setID(id);
    setName(fullname);
    setDay(day);
    setPhone(phone);
    setEmail(email);
    setEmployee_type(employee_type);
    setEmployee_count(employee_count);
    this->employee_count++;
}

// getter
std::string Employee::getID() const { return this->id; }
std::string Employee::getName() const { return this->fullname; }
Day Employee::getDay() const { return this->day; }
std::string Employee::getPhone() const { return this->phone; }
std::string Employee::getEmail() const { return this->email; }
Employee_type Employee::getEmployee_type() const { return this->employee_type; }
uint16_t Employee::getEmployee_count() const { return this->employee_count; }

void Employee::setID(const std::string &id) { this->id = id; }
void Employee::setName(const std::string &name) { this->fullname = fullname; }
void Employee::setPhone(const std::string &phone) { this->phone = phone; }
void Employee::setEmail(const std::string &email) { this->email = email; }
void Employee::setDay(const Day &Day) { this->day = day; }
void Employee::setEmployee_type(Employee_type employee_type) { this->employee_type = employee_type; }
void Employee::setEmployee_count(uint16_t employee_count) { this->employee_count = employee_count; }

void Employee::showInfo()
{
    std::cout << "=========INFO_EMPLOYEE=========" << std::endl;
    std::cout << "The id is: " << this->getID() << std::endl;
    std::cout << "The name is: " << this->getName() << std::endl;
    std::cout << "The phone is: " << this->getPhone() << std::endl;
    std::cout << "The Email is: " << this->getEmail() << std::endl;
    std::cout << "The Day is: " << this->getDay() << std::endl;
    std::cout << "The Employee_type is: " << this->getEmployee_type() << std::endl;
    std::cout << "The Employee_count is: " << this->getEmployee_count() << std::endl;
}

// void addCertificate(Certificate *certificate);
// void printCertificates(const std::string &certificateID) const;

void Employee::addCertificate()
{
    std::string certificateID;
    std::string certificateName;
    Rank certificateRank;
    uint8_t numCerts;
    uint8_t day, month, year;

    std::cout << "How many certificates does employee have? " << std::endl;
    std::cin >> numCerts;

    if (numCerts == 0)
    {
        std::cout << "The employee doesn't have any certificate !!!" << std::endl;
    }
    else
    {
        for (uint8_t i; i < numCerts; i++)
        {
            std::cout << "Enter the Certificate ID" << std::endl;
            std::cin >> certificateID;
            for (Certificate *certPtr : this->vec_cer)
            {
                if (certPtr->getCertificateID() == certificateID)
                {
                    std::cout << "The certficated with id " << certificateID << "has been added !! Please, add anthoer" << std::endl;
                }
                else
                {
                    std::cout << "Enter the certificate name: " << std::endl;
                    std::cin >> certificateName;
                    std::cout << "Enter the certificate rank: " << std::endl;
                    std::cin >> certificateRank;

                    std::cout << "Enter the Certificate day: " << std::endl;
                    std::cin >> day;
                    std::cout << "Enter the Certificate month: " << std::endl;
                    std::cin >> month;
                    std::cout << "Enter the Certificate year: " << std::endl;
                    std::cin >> year;

                    Day certday(day, month, year);
                    // Certificate(const std::string &certificateID, const std::string &certificateName, Rank certificateRank, const Day &certificateDate);
                    Certificate *certPtr = new Certificate(certificateID, certificateName, certificateRank, certday);
                    this->vec_cer.push_back(certPtr);
                }
            }
            std::cout << "Add " << numCerts << " certificates successfully!!!" << std::endl;
        }
    }
}

void Employee::printCertificates() const
{
    std::cout << "The employee with ID" << this->getID() << " has certificates:" << std::endl;
    for (Certificate *ptr : this->vec_cer)
    {
        std::cout << *ptr;
    }
}

void Employee::searchCertificate(const std::string &certificateID)
{
    for (Certificate *ptr : this->vec_cer)
    {
        if (ptr->getCertificateID() == id)
        {
            ptr->printCertificate();
        }
        else
        {
            std::cout << "the certificate id: " << certificateID << " not found!!" << std::endl;
        }
    }
}
