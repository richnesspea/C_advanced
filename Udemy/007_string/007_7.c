//Reverse a string

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void swap(char *a, char *b){
    char temp = *a;
    *a = *b;
    *b = temp;
}

int main(){
    char str1[7] = "python";
    char str2[7];
    //printf("size of the string: %d\n", sizeof(str1));
    strcpy(str2, str1);
    for(int i = 0; i < 3; i++){
        swap(&str2[i], &str2[6-i-1]);
    }
    printf("the reverse of the string: %s\n", str2);
}

