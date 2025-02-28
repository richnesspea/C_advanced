#include <stdio.h>

//Definition of one function

int myFunction(int x){
    return x *2;
}

void executeFunction(int (*functionPtr)(int), int value){
    int result = functionPtr(6);
    printf("%d \n", result);
}

int main(){
    //Declare a function pointer and assign it to the function
    int (*ptr)(int);
    ptr = &myFunction;

    //Call the function using funtion pointer
    int result = ptr(5);
    printf("%d\n", result);

    //Using function pointer in one function
    executeFunction(myFunction, 6);
}