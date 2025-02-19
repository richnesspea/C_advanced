#include "1_data_abstraction.h"

void Car::accelerate(){
    if(fuel > 0){
            speed += 10;
            fuel -=5;
            cout << brand << "is accelerating. Speed is " << speed << " and fuel is " << fuel << "%" << endl; 
        }
        else{
            cout << brand << "has no fuel" << endl;
        }
}

void Car::refuel(int amount){
    if(fuel < 100){
        fuel += amount;
        cout << brand << "fuled. Fuel: "<< fuel << "%" << endl;
    }
}


