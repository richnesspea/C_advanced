#include <stdio.h>

// Định nghĩa các trạng thái của hệ thống
typedef enum {
    STATE_IDLE,
    STATE_RUNNING,
    STATE_EXIT
} StateType;

// Định nghĩa kiểu dữ liệu cho một trạng thái, chứa thông tin trạng thái hiện tại và
// con trỏ hàm xử lý trạng thái đó.
typedef struct State {
    StateType type;
    void (*handler)(struct State*);
} State;

// Khai báo prototype của các hàm xử lý trạng thái
void idle_handler(State* state);
void running_handler(State* state);
void exit_handler(State* state);

// Hàm xử lý cho trạng thái "Idle"
void idle_handler(State* state) {
    printf("Trang thai Idle: Dang cho...\n");
    // Sau khi thực hiện các công việc của trạng thái Idle, chuyển sang trạng thái Running.
    state->type = STATE_RUNNING;
    state->handler = running_handler;
}

// Hàm xử lý cho trạng thái "Running"
void running_handler(State* state) {
    printf("Trang thai Running: Dang xu ly...\n");
    // Sau khi xử lý, chuyển sang trạng thái Exit.
    state->type = STATE_EXIT;
    state->handler = exit_handler;
}

// Hàm xử lý cho trạng thái "Exit"
void exit_handler(State* state) {
    printf("Trang thai Exit: Don dep va thoat.\n");
    // Không chuyển trạng thái nào nữa.
}

int main() {
    // Khởi tạo trạng thái ban đầu với Idle
    State current_state = { STATE_IDLE, idle_handler };

    // Vòng lặp xử lý trạng thái cho đến khi đạt trạng thái Exit
    while (current_state.type != STATE_EXIT) {
        current_state.handler(&current_state);
    }
    // Xử lý trạng thái Exit
    current_state.handler(&current_state);

    return 0;
}