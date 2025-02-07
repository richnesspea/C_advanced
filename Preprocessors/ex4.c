#include <stdio.h>

//Đoạn code này báo lỗi, vì sau khi nó kiểm tra điều kiện !x và nhận thấy là sẽ thực hiện câu lệnh ở
//condition else thì nó sẽ thực hiện printf ở vùng global scope -> mà statements thì phải nằm 
//bên trong 1 hàm -> vì vậy là không hợp lệ.

#define X 3
#if !X 
    printf("Geeks") 
#else 
    //printf("Quiz")

#endif
int main()
{
        return 0;
}