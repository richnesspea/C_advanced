#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void absoluteValue(uint8_t *data) {
    uint8_t a = data[0];
    uint8_t b = data[1];
    data[2] = (a > b) ? (a - b) : (b - a);
}

int main() {
    uint8_t data[3];
    char choice;
    
    do {
        printf("Enter two 8-bit positive numbers (0-255): \n");
        printf("The first number is: \n");
        scanf("%d ", &data[0]);
        printf("The second number is: \n");
        scanf("%d", &data[1]);
        
        absoluteValue(data);
        
        printf("First number: %d\n", data[0]);
        printf("Second number: %d\n", data[1]);
        printf("Absolute difference: %d\n", data[2]);
        
        printf("Do you want to continue? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');
    
    return 0;
}
