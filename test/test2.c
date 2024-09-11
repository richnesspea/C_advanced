#include <stdlib.h>
#include <stdio.h>
#include <string.h>  // Thêm thư viện để sử dụng hàm strlen

void intToBinaryString(int number, char* binaryStr) {
    int index = 0;

    // Số lượng bit cần để biểu diễn số nguyên
    int numBits = sizeof(int) * 8;
    for (int i = numBits - 1; i >= 0; i--) {
        int bit = (number >> i) & 1;  // Sửa từ & i thành & 1
        binaryStr[index++] = bit ? '1' : '0';
    }
    binaryStr[index] = '\0';  // Kết thúc chuỗi
}

int inspect_bits(unsigned int number) {
    char binaryStr[33];
    intToBinaryString(number, binaryStr);

    // Duyệt qua các phần tử trong chuỗi nhị phân
    for (int i = 0; i < strlen(binaryStr) - 1; i++) {  // Dùng strlen để tính độ dài chính xác
        if (binaryStr[i] == '1') {  // Kiểm tra ký tự là '1', không phải số 1
            if (binaryStr[i] == binaryStr[i + 1]) {
                return 1;  // Tìm thấy hai ký tự '1' liên tiếp
            }
        }
    }

    printf("%s \n", binaryStr);  // In chuỗi nhị phân
    return 0;
}

#ifndef RunTests
int main () {
    printf("%d \n", inspect_bits(13));  // Kiểm tra với số 13
}
#endif
