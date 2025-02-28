//Check if 2 strings are anagram distinct letters - using hashtable
//anagram: using the same set of alphabets

#include <stdio.h>
#include <string.h>

int main(){
    char A[] = "decimal";
    char B[] = "medical";
    int i;
    int H[26] = {0};
    for(i = 0; A[i] != '\0'; i++){
        H[A[i] - 97] += 1;
    }
    
    for(i = 0; B[i] != '\0'; i++){
        H[B[i] - 97] -= 1;
        if(H[B[i] - 97] < 0){
            printf("2 strings are not anagram \n");
            break;
        }
    }

    if(B[i] == '\0'){
        printf("2 strings are anagram \n");
    }
}