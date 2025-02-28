#include <stdio.h>

void updateAverage(int num1, int num2, float *avg){
    *avg = (float)(num1 + num2)/2;
}

int main(){
    int a, b;
    float average;
    a = 1000;
    b = 500;
    updateAverage(a, b, &average);
    printf("the average of a and b is: %f \n", average);
}