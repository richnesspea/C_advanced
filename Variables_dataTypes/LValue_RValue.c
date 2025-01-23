#include <stdio.h>

struct Person {
    char name[20];
    int age;
};

int main() {
    // L-value: Regular variable
    int x = 10;  // x is an L-value, as it has an identifiable memory location
    int y = 20;  // y is another L-value

    // R-value: Constant
    x = 30;  // x is on the left side (L-value), 30 is an R-value (constant)

    // L-value: Array with index expression
    int arr[5] = {1, 2, 3, 4, 5};
    arr[2] = 100;  // arr[2] is an L-value (array element at index 2)

    // L-value: Indirect reference via a pointer to an object
    struct Person person1 = {"Alice", 25};
    struct Person *ptr = &person1;  // ptr is a pointer to a structure

    // Using L-value to access structure member through pointer
    ptr->age = 26;  // ptr->age is an L-value (can modify)

    // R-value: Expression (result of an expression)
    y = x + 5;  // x + 5 is an R-value (temporary value, result of an expression)

    // L-value: Dereferencing a pointer
    int *p = &x;  // p is a pointer to x
    *p = 50;  // *p is an L-value (dereferencing the pointer to modify x)

    // L-value: Member access of a structure
    printf("Name: %s, Age: %d\n", person1.name, person1.age);

    // Print values of x and y
    printf("x: %d, y: %d\n", x, y);

    // Print modified array
    printf("arr[2]: %d\n", arr[2]);

    return 0;
}
