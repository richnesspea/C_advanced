#include <stdio.h>

typedef struct{
    char name[50];
    float age;
    int id;
}Employee;

void printEmployee(Employee emp){
    printf("Employee #1 name is %s \n", emp.name);
    printf("Employee #1 age is %f \n", emp.age);
    printf("Employee #1 id is %d \n", emp.id);
}

// void increaseAgeBy1(Employee emp){
//     emp.age ++;  
// }

void increaseAgeBy1(Employee *emp){
    (*emp).age ++;
}

int main(){
    Employee employee1 = {"Jake", 14.5, 1};
    printEmployee(employee1);
    increaseAgeBy1(&employee1);
    printEmployee(employee1);
}