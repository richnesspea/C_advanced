#include <stdio.h>
#include <stdint.h>

// Định nghĩa cấu trúc UART handle với nhiều callback
typedef struct {
    void (*RxCpltCallback)(void *huart);     // Con trỏ hàm callback khi nhận xong dữ liệu
    void (*ErrorCallback)(void *huart);      // Con trỏ hàm callback khi có lỗi
    uint8_t RxBuffer[10];                    // Buffer nhận dữ liệu
} UART_HandleTypeDef;

// Giả lập hàm ngắt của UART
void HAL_UART_IRQHandler(UART_HandleTypeDef *huart) {
    // Giả lập nhận được dữ liệu từ UART
    huart->RxBuffer[0] = 'H';
    huart->RxBuffer[1] = 'e';
    huart->RxBuffer[2] = 'l';
    huart->RxBuffer[3] = 'l';
    huart->RxBuffer[4] = 'o';
    huart->RxBuffer[5] = '\0';  // Kết thúc chuỗi

    // Kiểm tra có callback không và gọi hàm xử lý dữ liệu
    if (huart->RxCpltCallback) {
        huart->RxCpltCallback(huart);  // Truyền con trỏ huart để callback xử lý
    }
    
    // Kiểm tra có callback lỗi không
    if (huart->ErrorCallback) {
        huart->ErrorCallback(huart);  // Truyền con trỏ huart để xử lý lỗi nếu có
    }
}

// Hàm callback do người dùng định nghĩa - In dữ liệu lên màn hình
void My_UART_RxCpltCallback(void *huart) {
    UART_HandleTypeDef *uart = (UART_HandleTypeDef *)huart;
    printf("Data received: %s\n", uart->RxBuffer);
}

// Hàm callback xử lý lỗi
void My_UART_ErrorCallback(void *huart) {
    UART_HandleTypeDef *uart = (UART_HandleTypeDef *)huart;
    printf("Error in receiving data.\n");
}

// Hàm callback gửi dữ liệu qua một UART khác (giả lập)
void My_UART_TransmitCallback(void *huart) {
    UART_HandleTypeDef *uart = (UART_HandleTypeDef *)huart;
    printf("Sending data over another UART: %s\n", uart->RxBuffer);
}

int main() {
    // Khởi tạo UART handle
    UART_HandleTypeDef huart;

    // Gán con trỏ hàm callback cho handle
    huart.RxCpltCallback = My_UART_RxCpltCallback;
    huart.ErrorCallback = My_UART_ErrorCallback;
    
    // Giả lập ngắt UART (dữ liệu đã được nhận)
    HAL_UART_IRQHandler(&huart);

    // Thêm một callback nữa cho việc gửi dữ liệu qua UART khác
    huart.RxCpltCallback = My_UART_TransmitCallback;
    HAL_UART_IRQHandler(&huart);

    return 0;
}
