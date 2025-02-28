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

void printEmployeesArray(Employee* EmployeesArr, int totalElements){
    for (int i = 0; i < totalElements; i++){
        printf("the emploee age is: %d \n", EmployeesArr[i].age);
        printf("the emploee id is: %d \n", EmployeesArr[i].id);
    }
}

void CreateEmployeesArray2(Employee **empPtr, int totalElements){
    Employee* EmployeesArr;
    EmployeesArr = (Employee*)malloc(sizeof(Employee)* totalElements);
    for (int i = 0; i < totalElements; i++){
        printf("Enter the age \n");
        scanf("%d", &EmployeesArr[i].age);
        printf("Enter the id \n");
        scanf("%d", &EmployeesArr[i].id);
    }
    *empPtr = EmployeesArr;
}

int main(){
    Employee* ptrArr;
    int totalEmployees = 2;
    //ptrArr = CreateEmployeesArray(totalEmployees);
    CreateEmployeesArray2(&ptrArr, totalEmployees);
    printEmployeesArray(ptrArr, totalEmployees);
}