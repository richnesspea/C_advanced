//Finding duplicates in string using Hashtable or using Bits

#include <stdio.h>
#include <string.h>

int main(){
    char str[] = "longdeplong";
    int Hashtable[26] = {0};  // Khởi tạo mảng với tất cả phần tử bằng 0

    // Tăng số lần xuất hiện của mỗi ký tự
    for(int i = 0; str[i] != '\0'; i++){
        Hashtable[str[i] - 97] += 1;
    }

    // In ra các ký tự xuất hiện nhiều hơn 1 lần
    for(int i = 0; i < 26; i++){
        if(Hashtable[i] > 1){
            printf("%c: %d\n", i + 97, Hashtable[i]);
        }
    }

    return 0;
}
