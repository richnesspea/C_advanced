#include "../include/Certificate.hpp"

// Constructor
Certificate::Certificate(const std::string &certificateID, const std::string &certificateName, Rank certificateRank, Day certificateDay)
{
    setCertificateID(certificateID);
    setCertificateName(certificateName);
    setCertificateRank(certificateRank);
    setCertificateDate(certificateDay);
}

// Getter
std::string Certificate::getCertificateID() const { return this->certificateID; }
std::string Certificate::getCertificateName() const { return this->certificateName; }
Rank Certificate::getCertificateRank() const { return this->certificateRank; }
Day Certificate::getCertificateDate() const {return this->certificateDate;}


// Setter
void Certificate::setCertificateID(const std::string &certificateID) { this->certificateID = certificateID; }
void Certificate::setCertificateName(const std::string &certificateName) { this->certificateName = certificateName; }
void Certificate::setCertificateRank(Rank certificateRank) { this->certificateRank = certificateRank; }
void Certificate::setCertificateDate(const Day &certificateDate) { this->certificateDate = certificateDate; }

// Service function

void Certificate::printCertificate(void)
{
    std::cout << "The info of the Certificate: " << std::endl;
    std::cout << "The certificate ID: " << this->getCertificateID() << std::endl;
    std::cout << "The certificate Name: " << this->getCertificateName() << std::endl;
    std::cout << "The certificate Rank: " << this->getCertificateRank() << std::endl;
    std::cout << "The certificate Date: " << std::endl;
    this->getCertificateDate().printDay();

}
