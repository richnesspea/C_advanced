//Finding duplicates in string using Bitwise operation
#include <stdio.h>
#include <stdlib.h>


/*
1. Bitwise operations:
    * left shift <<
    * Masking A & B
    * Merging A | B
*/

int main(){

    //printf("%ld", sizeof(long int));
    char str[] = "finding"; 
    int H = 0;
    int x = 0;
    /*
        f: 102 - 97 = 5 -> set the bit 5 of int H 1
        i: 105 - 97 = 8 -> set the bit 8 of int H 1
        ...
    */
    for (int i = 0; str[i] != '\0'; i++){
        //printf("%d \n", str[i]);
        x = 1;
        x = x << (str[i]-97);
        if((x & H) > 0){
            printf("%c is duplicate \n", str[i]);
        }
        else{
            H = x | H;
        }
    }
}