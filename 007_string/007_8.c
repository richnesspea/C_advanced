//Compare the string
//Check palindrome

#include <stdio.h>
#include <string.h>

int main(){
    char str1[] = "Painter";
    char str2[] = "Longdeptrai";
    int i, j;
    for(i = 0, j = 0; str1[i] != '\0' && str2[i] != '\0'; i++, j++){
        if(str1[i] != str2[j]){
            break;
        }
    }
    if(str1[i] < str2[j]){
        printf("str1 is smaller than str2\n");
    }
    else if(str1[i] > str2[j]){
        printf("str1 is larger than str2\n");
    }
    else {
        printf("str1 is equal to str2\n");
    }

}