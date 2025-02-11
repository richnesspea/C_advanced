#include <stdio.h>
void f(char**);
int main()
{
    char *argv[] = { "ab", "cd", "ef", "gh", "ij", "kl" };
    printf("the address of ab: %d \n", argv);
    printf("the address of cd: %d \n", argv + 1);
    printf("the value that argv[4]: %s \n", *(argv + 4));
    printf("the size of ptr is: %d \n",sizeof(argv[0]));
    printf("the number of bytes between cd and ab is: %d \n", (char*)argv[1] - (char*)argv[0]);
    //Khai báo một mảng các con trỏ mà các con trỏ này trỏ đến các chuỗi string.
    f(argv); //Bản chất là đang truyền địa chỉ của phần tử đầu tiên trong mảng. -> Truyền địa chỉ của con trỏ đầu tiên trong mảng
            //Vì truyền địa chỉ của con trỏ -> để tác động thì hàm f phải nhận tham số đầu vào là con trỏ bậc 2
    return 0;
}
void f(char **p)
{
    char *t;

    printf("the address that p points to is: %d\n", p);
    t = (p += sizeof(int))[-1];//
    printf("the address that p points to is: %d\n", p);
    printf("%s\n", *p);
    
    printf("the address that t points to is: %d\n", &t);
    //p += sizeof(int): p = p + 4 -> p đang trỏ tới "ij" -> Về mặt bản chất không khác gì argv + 4 ở bên trên
    //t = p: gán (địa chỉ đầu tiên của mảng argv) cho con trỏ t
    printf("%s\n", t);
}
