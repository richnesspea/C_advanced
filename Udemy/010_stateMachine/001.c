#include <stdio.h>
#include <stdbool.h>

// Định nghĩa các trạng thái của công việc
typedef enum {
    STEP1,
    STEP2,
    STEP3,
    STEP4,
    FINISHED,
    ERROR
} WorkState;

// Hàm mô phỏng thực hiện từng bước
bool performStep1() {
    // Giả lập thực hiện Bước 1, trả về true nếu thành công
    return true;  // Thay đổi giá trị để kiểm tra các tình huống khác nhau
}

bool performStep2() {
    // Giả lập thực hiện Bước 2, trả về true nếu thành công
    return true; // Thay đổi giá trị để kiểm tra các tình huống khác nhau
}

bool performStep3() {
    // Giả lập thực hiện Bước 3, trả về true nếu thành công
    return false;  // Thay đổi giá trị để kiểm tra các tình huống khác nhau
}

bool performStep4() {
    // Giả lập thực hiện Bước 4, trả về true nếu thành công
    return true;  // Thay đổi giá trị để kiểm tra các tình huống khác nhau
}

// Hàm thực hiện công việc theo kiểu state machine
void executeWork() {
    WorkState state = STEP1;

    while (state != FINISHED && state != ERROR) {
        switch (state) {
            case STEP1:
                if (performStep1()) {
                    state = STEP2;
                } else {
                    printf("Error: Step 1 failed.\n");
                    state = ERROR;
                }
                break;

            case STEP2:
                if (performStep2()) {
                    state = STEP3;
                } else {
                    printf("Error: Step 2 failed.\n");
                    state = ERROR;
                }
                break;

            case STEP3:
                if (performStep3()) {
                    state = STEP4;
                } else {
                    printf("Error: Step 3 failed.\n");
                    state = ERROR;
                }
                break;

            case STEP4:
                if (performStep4()) {
                    state = FINISHED;
                    printf("All steps completed successfully.\n");
                } else {
                    printf("Error: Step 4 failed.\n");
                    state = ERROR;
                }
                break;

            default:
                state = ERROR;
                printf("Error: Unknown state.\n");
                break;
        }
    }
}

int main() {
    executeWork();  // Thực hiện công việc
    return 0;
}
