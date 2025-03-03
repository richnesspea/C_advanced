#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <iostream>
#include <string>
#include <cctype>
#include <vector>

enum Block{
    Block_A,
    Block_B,
    Block_C,
};


enum Priority {
    Level1,
    Level2,
    Level3,
};


class Student {
private:
    uint16_t id;
    std::string name;
    std::string address;
    Block block;
    Priority priority;
public:
    //Parameterized constructor
    Student(uint16_t id, const std::string &name, const std::string &address, Block block, Priority priority){
        setID(id);
        setName(name);
        setAddress(address);
        setBlock(block);
        setPriority(priority);
    }

    // Getter
    uint16_t getID() const;
    std::string getName() const;
    std::string getAddress() const;
    Block getBlock() const;
    Priority getPriority() const;

    // Setter
    void setID(uint16_t id);
    void setName(const std::string &name);
    void setAddress(const std::string &address);
    void setBlock(Block block);
    void setPriority(Priority priority);
};


#endif