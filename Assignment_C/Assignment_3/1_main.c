#include "1_header.h"

int main(){
    Array arr;
    InitArray(&arr, 5);
    AddElement(&arr, 10);
    AddElement(&arr, 6);
    AddElement(&arr, 7);
    AddElement(&arr, 188);
    printf("the array before sorting is: \n");
    PrintArray(&arr);
    Sort(&arr); //Using bubble sort
    printf("the array after sorting is: \n");
    PrintArray(&arr);
    freeArray(&arr);
}