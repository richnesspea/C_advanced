//Find the min and max of an array
#include <stdio.h>

#define SIZE 3
void minMaxArray(int *arr, int size, int *minValue, int *maxValue){
    *minValue = arr[0];
    *maxValue = arr[0];
    for(int i = 0; i < size; i++){
        if(*minValue > arr[i]){
            *minValue = arr[i];
        }
        if(*maxValue < arr[i]){
            *maxValue = arr[i];
        }
    }
}


int main(){
    int grades[SIZE] = {80, 90, 100};
    int min, max;
    minMaxArray(grades, SIZE, &min, &max);
    printf("the max value is: %d \n", max);
    printf("the min value is: %d \n", min);

}