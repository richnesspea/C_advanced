#include <stdio.h>
double calculate_final_speed(double initialSpeed, int inclinations[], int array_length) 
{
    // Waiting to be implemented

    for(int i = 0; i < array_length; i++){
        initialSpeed = initialSpeed - inclinations[i];
        if(initialSpeed <= 0){
            return 0;
        }
    }
    return initialSpeed;
    
}

#ifndef RunTests
int main() 
{
    int inclinations[] = { 0, 30, 0, -45, 0 };
    int array_length = sizeof(inclinations) / sizeof(inclinations[0]);
    int result;
    result = calculate_final_speed(60, inclinations, array_length);
    //printf("%.2f\n", calculate_final_speed(60, inclinations, array_length));
    return 0;
}
#endif
