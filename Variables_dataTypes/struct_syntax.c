#include <stdio.h>

// Define a structure
struct Person {
    char name[20];
    int age;
};

int main() {
    // Create an instance of the structure
    struct Person person1 = {"Alice", 30};
    
    // Create a pointer to the structure
    struct Person *ptr = &person1;

    // Using the dot operator to access members of structure person1
    printf("Using dot operator (.) with structure variable:\n");
    printf("Name: %s, Age: %d\n", person1.name, person1.age);

    // Using the arrow operator to access members through pointer ptr
    printf("\nUsing arrow operator (->) with pointer to structure:\n");
    printf("Name: %s, Age: %d\n", ptr->name, ptr->age);

    // Alternative way to access structure members using pointer with dereferencing
    printf("\nAlternative using dereferencing with pointer:\n");
    printf("Name: %s, Age: %d\n", (*ptr).name, (*ptr).age);

    return 0;
}
