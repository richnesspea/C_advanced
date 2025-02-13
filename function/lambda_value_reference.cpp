#include <iostream>

int main(){
    int a = 10;

    //the value of a is copied to lambda_by_value here.
    auto lambda_by_value = [a]() { 
        //std::cout << "Inside lambda: " << a << std::endl; 
    };

    a = 20;
    lambda_by_value();  // Output: Inside lambda: 10
    std::cout << "Outside lambda: " << a << std::endl; // Output: Inside lambda: 20

    auto lambda_by_ref = [&a]() { 
        //a += 5; 
        //std::cout << "Inside lambda: " << a << std::endl; 
    };

    lambda_by_ref();   // Output: Inside lambda: 25
    std::cout << "Outside lambda: " << a << std::endl;  // Output: Outside lambda: 25


    
}