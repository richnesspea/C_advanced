//Changing case of a string
#include <string.h>
#include <stdio.h>

int main(){

    char s[] = "WELCOME";
    for(int i = 0; s[i] != '\0'; i++){
        s[i] = s[i] + 32;
    }
    printf("%s \n", s);
}