#include "Employee.hpp"

int main(){
    //Employee(const std::string& name, uint8_t age, Gender gender)
    Employee employee1("DoQuangLong", 23, Gender::Male);
    std::cout << employee1.getName() << std::endl;
    std::cout << employee1.getAge() << std::endl;
    std::cout << employee1.getGender() << std::endl;
}