//Static variable
/*
I. Biến tĩnh cục bộ trong hàm
    1. Lưu trữ trạng thái: biến giữ giá trị giữa các lần gọi hàm, nhưng không muốn nó được truy cập từ ngoài hàm
    2. Tiết kiệm tài nguyên: tránh việc khởi tạo lại biến nhiều lần khi gọi hàm.
II. Biến tĩnh toàn cục
    1. chỉ có thể truy cập trong file chứa nó
*/

#include <stdio.h>
static int global_var = 10;

//Biến tĩnh cục bộ trong hàm
void counter(){
    //int count = 0;
    static int count = 0;
    count++;
    printf("Count = %d \n", count);
}

//Biến tĩnh ở cấp độ file
void increment(){
    global_var ++;
    printf("global variable value is: %d \n", global_var);
}

int main(){
    counter();
    counter();
    counter();
    increment();
    increment();
}