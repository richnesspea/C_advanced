#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int age;
    int id;
    char* name;
} Employee;

void CreateEmployeesArrayWithNames(Employee** empPtr, int totalEmployees){
    Employee* EmployeesArr;
    EmployeesArr = (Employee*)malloc(sizeof(Employee) * totalEmployees);
    for (int i = 0; i < totalEmployees; i++){
        printf("Enter the age \n");
        scanf("%d", &EmployeesArr[i].age);
        printf("Enter the id \n");
        scanf("%d", &EmployeesArr[i].id);
        
        //Allocate memory for the name
        EmployeesArr[i].name = (char*)malloc(100*sizeof(char)); 
        printf("Enter the name \n");
        scanf("%s", EmployeesArr[i].name);  
    }
    *empPtr = EmployeesArr;
}

void printEmployeesArrayWithNames(Employee* empPtr, int totalEmployees){
    for(int i = 0; i < totalEmployees; i++){
        printf("Employee age: %d \n", empPtr[i].age);
        printf("Employee id: %d \n", empPtr[i].id);
        printf("Employee name: %s \n", empPtr[i].name);
    }
}

void freeEmployeesArray(Employee* empPtr, int totalEmployees){
    for(int i = 0; i < totalEmployees; i++){
        free(empPtr[i].name);
    }
    free(empPtr);
}

void resizeEmployeeArray(Employee** empPtr, int currentSize, int newSize){
    Employee* EmployeesArr = (Employee*)realloc(*empPtr, newSize * sizeof(Employee));
    for(int i = currentSize; i < newSize; i++){
        printf("Enter the age for the new employee: \n");
        scanf("%d",&EmployeesArr[i].age);
        printf("Enter the id for the new employee: \n");
        scanf("%d",&EmployeesArr[i].id);

        //Allocate memory for the new employee's name
        EmployeesArr[i].name = (char *)malloc(100 * sizeof(char));
        printf("Enter the name for new employee: \n");
        scanf("%s", EmployeesArr[i].name);
    }
    *empPtr = EmployeesArr;
}



int main(){
    Employee* employees;
    int totalEmployees = 2;

    CreateEmployeesArrayWithNames(&employees, totalEmployees);
    printEmployeesArrayWithNames(employees, totalEmployees);

    int newSize = 4; // Resizing the array to hold 4 employees
    resizeEmployeeArray(&employees, totalEmployees, newSize);
    totalEmployees = newSize;

    printEmployeesArrayWithNames(employees, totalEmployees);
    freeEmployeesArray(employees, totalEmployees);
}