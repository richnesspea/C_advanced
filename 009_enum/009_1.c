#include <stdio.h>

// Định nghĩa các ngày trong tuần bằng enum
typedef enum {
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    SUNDAY
} Weekday;

int main() {
    Weekday day = 100;
    printf("%zu \n", sizeof(day));

    switch (day) {
    case MONDAY:
        printf("Today is MONDAY");
        break;
    case SUNDAY:
        printf("Today is Sunday");
        break;
    default:
        printf("Looking forward to the Weekend");
        break;
    }

    return 0;
}