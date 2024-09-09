//Find the length of the string

#include <string.h>
#include <stdio.h>

int main(){
    char s[] = "Welcome"; // Kí tự kết thúc '\0'
    int i;
    for (i = 0; s[i] != '\0'; i++);
    //printf("%d\n", i);
    printf("%d\n", (int)sizeof(s));
}

