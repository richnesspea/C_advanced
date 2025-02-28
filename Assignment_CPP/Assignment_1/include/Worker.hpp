#ifndef __WORKER_H__
#define __WORKER_H__

#include "Employee.hpp"

enum Worker_Level{
    Level1,
    Level2,
    Level3,
    Level4,
    Level5,
    Level6,
    Level7,
    Level8,
    Level9,
    Level10,
};

class Worker : public Employee {
private:
    Worker_Level level;
public:
    // Constructor
    Worker(const std::string& name, uint8_t age, Gender gender, Worker_Level level) : Employee(name, age, gender){
        setLevel(level);
    }  
    // Getter for level
    Worker_Level getLevel() const;
    // Setter for level
    void setLevel(Worker_Level level);
    // Getter for role
    std::string getRole() const override;
};


#endif