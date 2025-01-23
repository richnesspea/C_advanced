#include <stdio.h>


// Define an enum
enum Day {   // Enum representing the days of the week
    Sunday = 1,
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday
};

int main() {

    // Create and initialize an enum variable
    enum Day today = Wednesday;
    printf("size of enum Day: %u\n", sizeof(today));

    // Output the value from the enum
    printf("Today is day number: %d\n", today);  // Output will be 4 (Wednesday)

    // Enum example with a switch-case
    switch (today) {
        case Sunday: printf("It's Sunday!\n"); break;
        case Monday: printf("It's Monday!\n"); break;
        case Tuesday: printf("It's Tuesday!\n"); break;
        case Wednesday: printf("It's Wednesday!\n"); break;
        case Thursday: printf("It's Thursday!\n"); break;
        case Friday: printf("It's Friday!\n"); break;
        case Saturday: printf("It's Saturday!\n"); break;
        default: printf("Unknown day!\n"); break;
    }

    return 0;
}
