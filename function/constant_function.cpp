#include <iostream>
using namespace std;

class Car {
    private:
        int speed;
    
    public:
        int price;
        Car(int speed){
            this->speed = speed;
        }
        void setSpeed(int s) { speed = s; } // Regular function
        int getSpeed() const { 
            return speed; } // Const member function
    };
    
    int main() {
        const Car myCar(100); // Constant object
        //myCar.setSpeed(100); // ❌ Error: Cannot call non-const function
        int spd = myCar.getSpeed(); // ✅ Allowed: getSpeed() is a const function
        cout << spd << endl;
        return 0;
    }
    