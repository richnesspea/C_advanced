#include <stdio.h>
#include <stdlib.h>

// Uncomment this line to simulate missing macro definition
#define MCU_TYPE "STM32"

#define F_CPU 4000000  // Simulate a low clock speed

// Uncomment this to suppress certain warnings
// #define SUPPRESS_UNUSED_WARNING

#pragma message "Compiling for microcontroller project"

int main() {
    // Example of #error
    #ifndef MCU_TYPE
        #error "MCU_TYPE is not defined. Please define the MCU_TYPE for your target hardware."
    #endif

    printf("Target MCU: %s\n", MCU_TYPE);

    // Example of #warning
    #if F_CPU < 8000000
        #warning "Low clock speed may affect performance."
    #endif

    printf("CPU Frequency: %d Hz\n", F_CPU);

    // Example of #pragma diagnostic
    #pragma GCC diagnostic push
    #ifdef SUPPRESS_UNUSED_WARNING
        #pragma GCC diagnostic ignored "-Wunused-variable"
    #endif

    // This unused variable would normally trigger a warning
    int unused_variable;

    #pragma GCC diagnostic pop

    // Normal code execution
    printf("Microcontroller project is running.\n");

    return 0;
}
