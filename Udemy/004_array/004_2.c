#include <stdio.h>
//search if an element is in a given array
//find the maximum value in a given array and return it
#define SIZE 4

int sumArray(int *arr, int size){
    int sum = 0;
    for(int i = 0; i < size; i++){
        sum = sum + arr[i];
    }
    return sum;
}

double averageValue(int *arr, int size){
    int sum = sumArray(arr, size);
    return (double)sum/size;
}

int findKeyInArray(int *arr, int size, int key){
    for (int i = 0; i < size; i++){
        if(arr[i] == key){
            return 1;
        }
    }
    return 0;
}

int findMaxValueArray(int *arr, int size){
    int max = arr[0];

    if(size <=0){
        return -1;
    }
    for(int i = 1; i < size; i++){
        if (max < arr[i]){
            max = arr[i];
        }
    }
    return max;
}

int main (){
    int grades[SIZE] = {45, 46, 47, 81};
    int result;
    int key = 80;
    int maxValue;
    double averArr;

    result = findKeyInArray(grades, SIZE, key);
    maxValue = findMaxValueArray(grades, SIZE);
    averArr = averageValue(grades, SIZE);

    if (result == 1){
        printf("the key is: %d\n", key);
    }
    else printf("cannot find the key\n");

    printf("the max value in array is %d \n", maxValue);
    printf("the average value in given array is %f \n", averArr);

}