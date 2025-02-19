#include <iostream>
using namespace std;

class Robot_public{
    public:
    Robot_public(int id){
        robot_id = id;
        cout << "Robot created in public with id: " << robot_id << endl;
    }
    private:
        int robot_id;
};


class Robot_private{
    public:
        static Robot_private* createRobot(int id){ //we need static constructor as we need method independent of the object. 
            return new Robot_private(id);   //using new + function: dynamically allocated memory
        }
        void showID(){
            cout << "Robot_id of private:" << robot_id << endl;
        }
    private:
        int robot_id;
        Robot_private(int id){
            robot_id = id;
            cout << "Robot created in private with id: " << robot_id << endl;        
        }
};
int main(){
    //Constructor declared in public
    Robot_public r1(1);

    //Constructor declared in private
    Robot_private* r2 = Robot_private::createRobot(2);
    r2 -> showID();
    delete r2;

    return 0;
}



