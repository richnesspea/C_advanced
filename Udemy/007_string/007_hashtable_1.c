//Tìm kí tự đầu tiên không lặp lại
/*
    Một số bài tập khác liên quan đến hashtable (bảng băm):
        * Đảo ngược chuỗi giữ nguyên thứ tự xuất hiện của từ. Ví dụ: hello world -> world hello
        
*/
#include <stdio.h>
#include <string.h>


int main(){
    char str[] = "aabbccddeff";
    int Hashtable[256] = {0}; //Khởi tạo bảng băm cho tất cả kí tự ASCII

    // Đếm số lần xuất hiện mỗi kí tự 
    for(int i = 0; str[i] != '\0'; i++){
        Hashtable[(int)str[i]] += 1;
    }

    //Tìm kí tự đầu tiên không lặp lại
    for(int i = 0; str[i] != '\0'; i++){
        if(Hashtable[(int)str[i]] == 1){
            printf("Ky tu dau tien khong lap lai la: %c \n", str[i]);
            break;
        }
    }   
}