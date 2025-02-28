//Permutations of a string (hoán vị của 1 chuỗi kí tự)
/*
    1. State space tree
    2. Backtracking
    3. Brute force
    4. Recursion 
    => recursion -> backtracking -> brute force.
*/
#include <stdio.h>
#include <string.h>

/*
1. Giải thích đệ quy
    * Biến K để cho duyệt đến tận gốc
    * Biến I để duyệt xếp các phần tử
*/
void perm(char *str, int k){
    static int A[10] = {0};
    static char Res[10];
    if(str[k] == '\0'){
        Res[k] = '\0';
        //printf("%s \n", Res);
    }
    else {
        for(int i = 0; str[i] != '\0'; i++){
            if(A[i] == 0){
                Res[k] = str[i];
                A[i] = 1;
                perm(str, k+1);
                A[i] = 0;
            }
        }
    }
}

int main(){
    char s[] = "ABC";
    perm(s, 0);
}