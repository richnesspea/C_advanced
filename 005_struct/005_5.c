#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int age;
    int id;
}Employee;

Employee* CreateEmployeesArray(int totalElements){
    Employee* EmployeesArr;
    EmployeesArr = (Employee*)malloc(sizeof(Employee)*totalElements);
    for (int i = 0; i < totalElements; i++){
        printf("Enter the age \n");
        scanf("%d", &EmployeesArr[i].age);
        printf("Enter the id \n");
        scanf("%d", &EmployeesArr[i].id);
    }
    return EmployeesArr;
}