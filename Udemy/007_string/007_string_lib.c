#include <stdio.h>
#include <string.h>

#define MAX_LEN 100



int main() {
    char str1[MAX_LEN] = "123";
    char str2[MAX_LEN] = "abc";
    char c = 'a';
    
    
    str1[strcspn(str1, "\n")] = '\0';  // Xóa ký tự newline nếu có
    str2[strcspn(str2, "\n")] = '\0';  // Xóa ký tự newline nếu có

    // Tính độ dài của hai chuỗi
    printf("Độ dài chuỗi 1: %ld\n", strlen(str1));
    printf("Độ dài chuỗi 2: %ld\n", strlen(str2));

    // Sao chép chuỗi 2 vào chuỗi 1
    strcpy(str1, str2);
    printf("Chuỗi 1 sau khi sao chép chuỗi 2: %s\n", str1);

    // Ghép chuỗi 2 vào cuối chuỗi 1
    strcat(str1, str2);
    printf("Chuỗi 1 sau khi ghép chuỗi 2: %s\n", str1);

    // Tìm ký tự trong chuỗi 1
    char *charFound = strchr(str1, c);
    if(charFound) {
        printf("Ký tự '%c' xuất hiện đầu tiên tại vị trí: %ld\n", c, charFound - str1);
    } else {
        printf("Ký tự '%c' không tồn tại trong chuỗi 1\n", c);
    }

    // Tìm chuỗi con trong chuỗi 1
    str2[strcspn(str2, "\n")] = '\0';  // Xóa ký tự newline nếu có

    char *subStrFound = strstr(str1, str2);
    if(subStrFound) {
        printf("Chuỗi con '%s' xuất hiện đầu tiên tại vị trí: %ld\n", str2, subStrFound - str1);
    } else {
        printf("Chuỗi con '%s' không tồn tại trong chuỗi 1\n", str2);
    }


    return 0;
}
