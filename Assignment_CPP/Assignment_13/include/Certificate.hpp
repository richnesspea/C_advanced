#ifndef __CERTIFICATE_HPP__
#define __CERTIFICATE_HPP__

#include <iostream>
#include "Date.hpp"


enum Rank {
    Intermediate,
    Good,
    Excellent,
};

class Certificate {
private:
    std::string certificateID;
    std::string certificateName;
    Rank certificateRank;
    Day certificateDate;
public:
    // Constructor
    Certificate(const std::string &certificateID, const std::string &certificateName, Rank certificateRank, Day certificateDate);

    // Getter
    std::string getCertificateID() const;
    std::string getCertificateName() const;
    Rank getCertificateRank() const;
    Day getCertificateDate() const;

    // Setter
    void setCertificateID(const std::string &certificateID);
    void setCertificateName(const std::string &certificateName);
    void setCertificateRank(Rank certificateRank);
    void setCertificateDate(const Day &certificateDate);

    // Some service function
    void printCertificate(void);
};


#endif
