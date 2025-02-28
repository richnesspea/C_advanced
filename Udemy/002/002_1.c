#include <stdio.h>

int main(){
    //1 byte = 8 bit
    //1 int chiếm 4 bytee
    //1 double chiếm 8 byte
    int a;
    int grades[3] = {80, 90, 100};
    double grades_double[3] = {80.5, 90.2, 95.6};
    int *gradesPtr = grades;
    double *grades_doublePtr = grades_double;

    printf("%zu \n", sizeof(a));

    printf("grades start at: %p \n", grades);
    printf("gradesPtr at: %p \n", gradesPtr); //printed: 0x7ffed4ff935c -> each int var needs 4 byte 
    printf("grades +1 start at: %p \n", gradesPtr + 1); //printed: 0x7ffed4ff9360 
    //printf("grades +1 start at: %p \n", gradesPtr + 1 * sizeof(int));
    printf("grades_double start at: %p \n", grades_doublePtr); 
    printf("grades_double -1 start at: %p \n", grades_doublePtr - 1); 
    //printf("grades_double -1 start at: %p \n", grades_doublePtr - 1 * sizeof(double)); // 38 39 3a 3b 3c 3d 3e 3f => 8 byte
}