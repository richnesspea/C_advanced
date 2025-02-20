#ifndef __CAR_H__
#define __CAR_H__

#include  <iostream>
using namespace std;

class Car {
public:
    Car(string b, int f) : brand(b), speed(0), fuel(f) {};
    void accelerate();
    void refuel(int amount);
private:
    string brand;
    int speed;
    int fuel;
};

#endif
