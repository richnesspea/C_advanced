#include <stdio.h>
#include <stdint.h>

int main(){
    uint8_t buffer[4] = {0x01, 0x02, 0x03, 0x04};
    uint32_t data_32 = 0x12345678;

    uint8_t *data_8 = buffer;
    
    uint32_t *data = (uint32_t*)buffer;  // Ép kiểu sang uint32_t* -> hệ thống little-ended: Byte có trọng số nhỏ nhất (Least Significant Byte - LSB) được lưu ở địa chỉ nhỏ nhất.
    uint8_t* data_8_tc = (uint8_t*)&data_32;

    printf("Data_8: %d\n", *data_8);
    
    printf("Data: %d\n", *data);
    printf("Data: 0x%X\n", *data);  // In ra dữ liệu dưới dạng 32-bit

    printf("Data_8_tc: %d\n", *data_8_tc);
    printf("Data_8_tc: 0x%X\n", *data_8_tc);  


}