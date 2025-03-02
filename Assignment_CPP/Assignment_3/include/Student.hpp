#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <iostream>
#include <string>


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
    uint32_t id;
    std::string name;
    std::string address;
    Block block;
    Priority priority;
public:
    // Getter
    uint32_t getID() const;
    std::string getName() const;
    std::string getAddress() const;
    Block getBlock() const;
    Priority getPriority() const;

    // Setter
    void setID(uint32_t id);
    void setName(const std::string &name);
    void setAddress(const std::string &address);
    void setBlock(Block block);
    void setPriority(Priority priority);
};


#endif