#include <stdio.h>
#include <unistd.h>  // Thư viện cho hàm usleep()
#include <time.h>    // Thư viện cho hàm time()

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
    Weekday day = MONDAY;
    Weekday targetDay = SUNDAY; // Ngày cần đạt được
    int success = 0; // Biến để kiểm tra thành công
    time_t startTime = time(NULL); // Thời gian bắt đầu

    // Vòng lặp để thử lại nếu cần
    while (!success) {
        // Kiểm tra nếu đã quá 10 giây
        if (difftime(time(NULL), startTime) > 10) {
            printf("Exceeded 10 seconds. Exiting...\n");
            break; // Thoát khỏi vòng lặp
        }

        switch (day) {
            case MONDAY:
                printf("Today is MONDAY\n");
                break;
            case TUESDAY:
                printf("Today is TUESDAY\n");
                break;
            case WEDNESDAY:
                printf("Today is WEDNESDAY\n");
                break;
            case THURSDAY:
                printf("Today is THURSDAY\n");
                break;
            case FRIDAY:
                printf("Today is FRIDAY\n");
                break;
            case SATURDAY:
                printf("Today is SATURDAY\n");
                break;
            case SUNDAY:
                printf("Today is SUNDAY\n");
                success = 1; // Thành công khi đạt đến ngày SUNDAY
                break;
            default:
                printf("Invalid day\n");
                break;
        }

        if (!success) {
            // Nếu không thành công, đợi 100ms rồi thử lại
            usleep(100000); // 100000 microseconds = 100ms
            // Tiến đến ngày tiếp theo
            day = (day + 1) % 5; // Di chuyển đến ngày tiếp theo trong tuần
        }
    }

    return 0;
}