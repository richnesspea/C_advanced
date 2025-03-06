#include "Employee.hpp"
#include <iostream>





std::ostream& operator<<(std::ostream& COUT, const Certificate& certificate){
    COUT << "Certificate ID: " << certificate.getCertificateID() << std::endl;
    COUT << "Certificate Name: " << certificate.getCertificateName() << std::endl;
    COUT << "Certificate Rank: " << certificate.getCertificateRank() << std::endl;
    COUT << "Certificate Date: " << certificate.getCertificateDate() << std::endl;
}


std::ostream& operator<<(std::ostream& COUT, const Day& day)
{
    COUT << static_cast<int>(day.getDay()) << "/"
         << static_cast<int>(day.getMonth()) << "/"
         << static_cast<int>(day.getYear());
    return COUT;
}

std::ostream &operator<<(std::ostream &COUT, Employee_type employee_type)
{
    switch (employee_type)
    {
    case Employee_type::Experience:
        COUT << "Experience";
        break;
    case Employee_type::Fresher:
        COUT << "Fresher";
        break;
    case Employee_type::Intern:
        COUT << "Intern";
        break;
    }
    return COUT;
}

std::ostream &operator<<(std::ostream &COUT, Rank& rank)
{
    switch (rank)
    {
    case Rank::Excellent:
        COUT << "Excellent";
        break;
    case Rank::Good:
        COUT << "Good";
        break;
    case Rank::Intermediate:
        COUT << "Intermediate";
        break;
    }
    return COUT;
}


std::istream& operator>>(std::istream& CIN, Day& day)
{
    
}

std::istream& operator>>(std::istream& CIN, Certificate& certificate){
    std::string certificateID;
    std::string certificateName;
    Rank certificateRank;
    Day certificateDate;
    
    std::cout << "Enter the certificateID" << std::endl;
    CIN >> certificateID;
    certificate.setCertificateID(certificateID);
    
    std::cout << "Enter the certificateName" << std::endl;
    CIN >> certificateName;
    certificate.setCertificateName(certificateName);

    std::cout << "Enter the certificateRank" << std::endl;
    CIN >> certificateRank;
    certificate.setCertificateRank(certificateRank);
}




std::istream &operator>>(std::istream &CIN, Employee_type &employee_type)
{
    std::string input;

    do
    {
        std::cout << "Enter the Employee_type (Experience/Fresher/Intern): " <<std::endl;
        CIN >> input;
        if (input == "Experience")
        {
            employee_type = Employee_type::Experience;
            break;
        }
        if (input == "Fresher")
        {
            employee_type = Employee_type::Fresher;
            break;
        }
        if (input == "Intern")
        {
            employee_type = Employee_type::Intern;
            break;
        }
    } while (true);
    return CIN;
}

std::istream &operator>>(std::istream &CIN, Rank rank)
{
    std::string input;

    do
    {
        std::cout << "Enter the Rank (Excellent/Good/Intermediate): " <<std::endl;
        CIN >> input;
        if (input == "Experience")
        {
            rank = Rank::Excellent;
            break;
        }
        if (input == "Good")
        {
            rank = Rank::Good;
            break;
        }
        if (input == "Intermedidate")
        {
            rank = Rank::Intermediate;
            break;
        }
    } while (true);
    return CIN;
}

static void displayMenu(){
    std::cout << "\n===== Employee Management System =====\n";
    std::cout << "1. Add Employee\n";
    std::cout << "2. Modify Employee Information\n";
    std::cout << "3. Show All Employees\n";
    std::cout << "4. Show All Interns\n";
    std::cout << "5. Show All Freshers\n";
    std::cout << "6. Show All Experienced Employees\n";
    std::cout << "7. Exit\n";
    std::cout << "=======================================\n";
    std::cout << "Enter your choice: ";
}


void Employee_Manager_loop(void){
    Employee_manager manager;
    bool flag;
    int choice;
    while(flag){
        displayMenu();
        switch (choice)
        {
        case 1:
            manager.addEmployee();
            break;
        
        default:
            std::cout << "Invalid choice. Please try again" << std::endl;
        }
    }
    

}




