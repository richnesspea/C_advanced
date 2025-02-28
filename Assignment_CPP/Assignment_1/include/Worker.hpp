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
    Worker(const std::string& name = "DefaultName", uint8_t age = 17, Gender gender = Gender::Others, Worker_Level level = Worker_Level::Level1) : Employee(name, age, gender){
        setLevel(level);
    }  
    
    // Setter for level
    void setLevel(Worker_Level level);

    // Getter for role
    Work_Type getRole() const override;
    // Getter for level
    Worker_Level getLevel() const;

    // Input data
    void inputData() override;

};


#endif