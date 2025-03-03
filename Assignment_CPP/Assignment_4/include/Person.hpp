#ifndef __PERSON_HPP__
#define __PERSON_HPP__

#include <iostream>


class Person{
private:
    std::string name;
    uint8_t age;
    std::string job;
    std::string id;
public:
    // Default constructor;
    Person(){
        this->name = "Unknown";
        this->age = 0;
        this->job = "None";
        this->id = "None";
    }

    // Parameterized constructor
    Person(const std::string &name, uint8_t age, const std::string &job, const std::string id){
        setName(name);
        setAge(age);
        setJob(job);
        setID(id);
    }
    // Virtual destructor


    // Getter
    std::string getID() const;
    std::string getName() const;
    std::string getJob() const;
    uint8_t getAge() const;

    // Setter
    void setID(const std::string &id);
    void setName(const std::string &name);
    void setJob(const std::string &job);
    void setAge(uint8_t age);
};



#endif