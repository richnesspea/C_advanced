#include <stdio.h>
// Consider this C code to swap two integers and these five statements after it:
void swap(int *px, int *py) 
{ 
   *px = *px - *py; 
   *py = *px + *py; 
   *px = *py - *px; 
}

int main(){
    return 0;
}
// S1: will generate a compilation error -> sai. Vì khối lệnh trên đúng về mặt syntax.
// S2: may generate a segmentation fault at runtime depending on the arguments passed -> Đúng. Vì nếu truyền con trỏ NULL vào hàm thì kiểu gì cũng lỗi
// S3: correctly implements the swap procedure for all input pointers referring to integers stored in memory locations accessible to the process
//      -> Sai vì nếu truyền địa chỉ của cùng 1 biến vào cả px và py thì kết quả bằng 0 chứ ko swap
// S4: implements the swap procedure correctly for some but not all valid input pointers -> ĐÚng vì trường hợp trỏ NULL và cùng địa chỉ của 1 biến
// S5: may add or subtract integers and pointers. -> sai vì ko có thao tác với con trỏ. Nếu muốn thì phải là con trỏ bậc 2