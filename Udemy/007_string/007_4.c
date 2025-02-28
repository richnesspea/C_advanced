//Changing case of a string
#include <string.h>
#include <stdio.h>

int main(){

    char s[] = "LongHasABigDick";
    for(int i = 0; s[i] != '\0'; i++){
        if(s[i] >= 'a' && s[i] <= 'z'){
            s[i] = s[i] - 32;
        }
        else if(s[i] >= 'A' && s[i] <= 'Z'){
            s[i] = s[i] + 32;
        }
    }
    printf("%s \n", s);
}