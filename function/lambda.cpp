#include <iostream>
#include <functional>

int main(){
    int x = 10;
    int y = 20;

    auto sayHello = [](){
        std::cout << "example of basic lambda" << std::endl;
    };

    auto lambda_params = [](int a, int b) -> int{
        return a + b;        
    };

    auto lambda_capture = [x, y]() -> int{
        return x * y;
    };

    auto lambda_capture_param = [x, y](int a, int b) -> int{
        a = a + x;
        b = y + b/10;
        return a + b;
    };

    sayHello();

    std::cout << "example of lambda_params: " << lambda_params(5, 10) << std::endl; 
    std::cout << "example of lambda_capture: " << lambda_capture() << std::endl; 
    std::cout << "example of lambda_capture_param: " << lambda_capture_param(5, 10) << std::endl; 

    std::cout << "size of lambda_params: " << sizeof(lambda_params) << std::endl;
                                            //sizeof(lambda_params(5,10)): calculate the RETURN type size 
    std::cout << "size of sayHello: " << sizeof(sayHello) << std::endl; 
    std::cout << "size of lambda_capture: " << sizeof(lambda_capture) << std::endl; 
    std::cout << "size of lambda_capture_param: " << sizeof(lambda_capture_param) << std::endl;

    return 0;
}
