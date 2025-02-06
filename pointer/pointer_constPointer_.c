#include <stdio.h>
#include <stdint.h>

#define __vo volatile
#define GPIO_PIN_SET    1
#define GPIO_PIN_RESET  0

// Địa chỉ cơ bản của GPIOA trên STM32F4 (ví dụ)
#define GPIOA_BASEADDR  0x40020000
#define GPIOA           ((GPIO_RegDef_t*) GPIOA_BASEADDR)   //GPIO_RegDef_t là một con trỏ đến 1 cấu trúc, có chức năng để can thiệp đến các thành phần trong cấu trúc

#define FLASH_DATA_ADDR 0x08004000
#define FLASH_DATA      ((const uint32_t*) FLASH_DATA_ADDR) //type casting pointer bởi vì ban đầu 0x08004000 chỉ được hiểu là một số nguyên, nếu compile 
                                                            //trình biên dịch sẽ báo lỗi. Nên cần thiết phải ép kiểu để biến nó thành một con trỏ.


typedef struct {
    __vo uint32_t MODER;         //offset: 0x00
    __vo uint32_t OTYPER;        //offset: 0x04
    __vo uint32_t OSPEEDR;       //offset: 0x08
    __vo uint32_t PUPDR;         //offset: 0x0C
    __vo uint32_t IDR;           //offset: 0x10
    __vo uint32_t ODR;           //offset: 0x14
    __vo uint32_t BSRR;          //offset: 0x18
    __vo uint32_t LCKR;          //offset: 0x1C
    __vo uint32_t AFR[2];        //offset: 0x20
}GPIO_RegDef_t; //GPIO register definition

void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint16_t Value){
    if(Value == GPIO_PIN_SET){
        pGPIOx->ODR |= (1 << PinNumber); 
    }
    else {
        pGPIOx->ODR &= ~(1 << PinNumber);
    }
}

//Ví dụ về const pointer
void GPIO_WriteToOutputPin_const(GPIO_RegDef_t *const pGPIOx, uint8_t PinNumber, uint16_t Value) {
    if (Value == GPIO_PIN_SET) {
        pGPIOx->ODR |= (1 << PinNumber);
    } else {
        pGPIOx->ODR &= ~(1 << PinNumber);
    }
}


//Ví dụ về pointer to const
void GPIO_ReadInputPin(const GPIO_RegDef_t *pGPIOx, uint8_t PinNumber) {
    uint32_t pinValue = (pGPIOx->IDR >> PinNumber) & 0x1;  // Đọc giá trị của chân PinNumber
    printf("Pin %d value: %d\n", PinNumber, pinValue);

    // Không thể thay đổi dữ liệu trong pGPIOx vì nó là const
    // pGPIOx->ODR |= (1 << PinNumber);  // Lỗi: không thể ghi dữ liệu vào ODR
}

//Ví dụ về const pointer to const value

void ReadFlashData(const uint32_t *const flashAddress, uint8_t length) {
    printf("Reading data from Flash:\n");
    for (uint8_t i = 0; i < length; i++) {
        printf("Data[%d]: 0x%08X\n", i, flashAddress[i]);
    }
}

int main(){
    // Giả định cấu hình GPIOA pin 5 làm output (MODER5 = 01), GPIO là một con trỏ kiểu cấu trúc
    GPIOA->MODER &= ~(0b11 << (5 * 2));  // Xóa 2 bit tại vị trí MODER5, GPIOA trỏ đến thành phần MODER của struct.
    GPIOA->MODER |=  (0b01 << (5 * 2));  // Thiết lập MODER5 thành 01 (output)


    //Đọc dữ liệu từ flash
    const uint32_t *const flash_data = FLASH_DATA; //Khai báo biến flash_data là một kiểu const pointer to const data
    uint8_t length = 5;
    ReadFlashData(flash_data, length); 


    while (1) {
        // Bật GPIOA pin 5
        GPIO_WriteToOutputPin(GPIOA, 5, GPIO_PIN_SET);  
        for (volatile int i = 0; i < 100000; i++);  // Delay

        // Tắt GPIOA pin 5
        GPIO_WriteToOutputPin(GPIOA, 5, GPIO_PIN_RESET);
        for (volatile int i = 0; i < 100000; i++);  // Delay
    }
    return 0;
}



