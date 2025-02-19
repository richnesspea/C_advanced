#include <iostream>
#include <functional>
using namespace std;


// Higher-order functions: takes another function as an argument
void executeCommand(std::function<void()> action){
    cout << "Executing the command ..." << endl;
    action();
}


int main(){
    //Define robot actions using lambda functions
    auto moveForward = [](){
        cout << "Move forward" << endl;
    };
    auto turnLeft = [](){
        cout << "Turn left" << endl;
    };
    auto turnRight = [](){
        cout << "Turn right" << endl;
    };

    executeCommand(turnLeft);
    executeCommand(turnRight);
    executeCommand(moveForward);

}
