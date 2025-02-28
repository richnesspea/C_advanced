//Compare the string
//Check palindrome

#include <stdio.h>
#include <string.h>

void checkPalindrome(char *str, int size){
    int i;
    for (i = 0; i < size/2; i++){
        if(str[i] != str[size-2-i]){
            printf("the str is not palindrome \n");
            break;
        }
    }
    if(i >= size/2){
        printf("the str is palindrome \n");
    }

}

int main(){
    char str1[] = "Painter";
    char str2[] = "Longdeptrai";
    char str3[] = "121";
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
    
    //check palindrome
    int size_str = sizeof(str3);
    printf("the size of str3 is %d\n", size_str);
    checkPalindrome(str3, size_str);
}