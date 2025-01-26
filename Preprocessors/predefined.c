#include <stdio.h>

int main() {
    printf("Predefined Macros in C:\n");

    // __FILE__: Tên file hiện tại
    printf("File Name: %s\n", __FILE__);

    // __LINE__: Dòng mã hiện tại
    printf("Current Line: %d\n", __LINE__);

    // __DATE__: Ngày biên dịch
    printf("Compilation Date: %s\n", __DATE__);

    // __TIME__: Thời gian biên dịch
    printf("Compilation Time: %s\n", __TIME__);

    // __STDC__: Kiểm tra xem trình biên dịch có tuân theo tiêu chuẩn C hay không
    #ifdef __STDC__
        printf("Compiler follows the ANSI C standard.\n");
    #else
        printf("Compiler does not follow the ANSI C standard.\n");
    #endif

    // __STDC_VERSION__: Hiển thị phiên bản chuẩn C
    #ifdef __STDC_VERSION__
        printf("C Standard Version: %ld\n", __STDC_VERSION__);
    #endif

    return 0;
}
