#include <stdio.h>

// Define a struct
struct Employee {
    int id;            
    char name[20];     
    double salary;     
};

// Define a union
union Data {
    int i;             
    float f;           
    char str[20];      
};

int main() {
    // Create and initialize a struct instance
    struct Employee emp1;
    emp1.id = 101;
    printf("size of emp1: %d\n", sizeof(emp1));
    snprintf(emp1.name, sizeof(emp1.name), "John");
    printf("size of emp1: %d\n", sizeof(emp1));
    emp1.salary = 55000.75;
    printf("size of emp1: %d\n", sizeof(emp1));

    // Create and initialize a union instance
    union Data data1;
    printf("size of emp1: %d\n", sizeof(data1));
    data1.i = 10;  // Initially storing integer
    printf("the value of data1.i: %d\n", data1.i);
    data1.f = 3.14;  // Uncommenting this would overwrite the integer value
    printf("the value of data1.i: %d\n", data1.i);
    printf("the value of data1.f: %f\n", data1.f);

    snprintf(data1.str, sizeof(data1.str), "Hello");  // Uncommenting this would overwrite the previous value
    printf("the value of data1.f: %f\n", data1.f);

    return 0;
}
