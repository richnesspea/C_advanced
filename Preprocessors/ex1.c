#include <stdio.h>

//the difference between while and do_while
//continue: skipt the rest of code in loop while or loop for 

#define PRINT(i, limit) do { if (i++ < limit) { printf("%d\n",i); continue;} }while(1)
//i++ sẽ kiểm tra điều kiện trong if trước rồi mới tăng giá trị của i
//sau khi i++ một thời gian nó sẽ bị tràn bộ nhớ, nên i sẽ chuyển thành số âm và vì thế sẽ bị nhỏ hơn limit nên in ra vô số lần.
 
int main()
{
    int i = 0;
    PRINT(i, 3);
    return 0;
}