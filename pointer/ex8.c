#include <stdio.h>
int main()
{
    char *ptr = "GeeksQuiz";
    printf("%d\n", ptr);
    printf("%d\n", &*ptr);
    printf("%c\n", *&*&*ptr);
    //Phân tích câu lệnh *&*&*ptr
    //*ptr để lấy giá trị mà con trỏ ptr đang trỏ tới. Ở đây là kí tự "G"
    //&(*ptr): Lấy địa chỉ của (*ptr) hay chính là giá trị của ptr
    //Làm lần lượt và cuối cùng chính là giá trị mà con trỏ ptr đang trỏ tới.
    return 0;
}
