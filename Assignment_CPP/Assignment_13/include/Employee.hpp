#ifndef __EMPLOYEE_H__
#define __EMPLOYEE_H__

#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include "Date.hpp"
#include "Certificate.hpp"


enum Employee_type
{
    Experience_employee,
    Fresher_employee,
    Intern_employee,
};

class Employee
{
protected:
    
    std::string id;
    std::string fullname;
    std::string phone;
    std::string email;
    Employee_type employee_type;
    static uint16_t employee_count;
    Day day;
    std::vector<Certificate*>vec_cer;

public:
    // Constructor
    Employee(const std::string &id, const std::string &fullname, const Day &day, const std::string &phone, const std::string &email, Employee_type employee_type);
    // We don't need copy and move constructor because std::string have its own default ones.
    virtual ~Employee() = default;

    // Getter
    std::string getID() const;
    std::string getName() const;
    Day getDay() const;
    std::string getPhone() const;
    std::string getEmail() const;
    Employee_type getEmployee_type() const;
    uint16_t getEmployee_count() const;

    // Setter
    void setID(const std::string &id);
    void setName(const std::string &fullname);
    void setDay(const Day &day);
    void setPhone(const std::string &phone);
    void setEmail(const std::string &email);
    void setEmployee_type(Employee_type Employee_type);
    void setEmployee_count(uint16_t employee_count);
    void showInfo(void);
    
    // Service certificate
    void addCertificate();
    void printCertificates(void) const;
    void searchCertificate(const std::string &certificateID);

    // virtual function
    virtual void showMe() = 0;
};

#endif