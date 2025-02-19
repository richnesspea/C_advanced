#include "1_data_abstraction.h"

int main(){
    Car MyCar("BMW", 50); //default speed is 0
    MyCar.accelerate();
    MyCar.accelerate();
    MyCar.accelerate();
    MyCar.refuel(10);
    return 0;
}
