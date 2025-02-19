// Defining the constructor outside the class

#include <iostream>
#include <string>
using namespace std;

class Student{
    private:
        int rno;
        string name;
        double fee;
    public:
        Student(int rno, const string& name, double fee);//like a method. We have 2 ways to define a method (inside and outside), so constructor is no exception
        void display();
};

Student::Student(int rno, const string& name, double fee){
    this->rno = rno;
    this->name = name;
    this->fee = fee;
}

void Student::display(){
    cout << rno << " " << name << " " << fee << endl;    
}

int main(){
    Student student1(12, "Long", 200.0);
    student1.display();
}
