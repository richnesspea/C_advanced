#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Write a function to find the longest common prefix string amongst an array of strings.
// If there is no common prefix, return an empty string "".

// Example 1:
// Input: strs = ["flower","flow","flight"]
// Output: "fl"

// Example 2:
// Input: strs = ["dog","racecar","car"]
// Output: ""
// Explanation: There is no common prefix among the input strings.

// Explanation of char* versus char
// char* strs1[] means that strs1 is an array of pointers, where each pointer is a char* pointing to the start of a string.
// Each of the strings ("flower", "flow", "flight") is stored as a string literal, which is typically stored in a read-only section of memory. Each literal is represented by a pointer to its first character.
// Using char* allows each element of strs1 to simply store the address (pointer) of the first character of each string, which is more memory efficient than duplicating each string into an array of chars.
// If strs1 were declared as char strs1[][], it would imply a 2D array where the exact size of each string must be known in advance (e.g., char strs1[3][10]). This is less flexible because each string in the array would need to have the same length, and modifying this size would require changing the declaration.



//https://viblo.asia/p/trie-tree-phan-1-xu-ly-xau-ki-tu-5pPLk96n4RZ: trie tree
//https://wiki.vnoi.info/translate/wcipeg/tree: tree 

char* longestCommonPrefix(char** strs, int strsSize) {
    //strs is a pointer to a pointer of a char
    if(strsSize == 0){
        return "";
    }

    //Allocate memory for the prefix result
        //strlen(): caculate the length of string 
        //sizeof(): calculate the memory allocated for the array
    char* result = (char*)malloc((strlen(strs[0]) + 1) * sizeof(char));
    if(result == NULL){
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    
    //Initialize the result with the first string in the array
    strcpy(result, strs[0]);//char * strcpy ( char * destination, const char * source ); -> strcpy returns a pointer to the destination string

    for(int i = 0; i < strsSize; i++){
        int j = 0;
        while(result[j] && strs[i][j] && result[j] == strs[i][j]){
            //result[j] is used to check whether the for loop has reached the end of the string
            //strs[i][j] is the characer at index j in the i-th string in the array. This is used to check that character is not NULL
            j++;
        }

        //The last character of the string will be updated
        result[j] = '\0';

        if (j == 0){
            free(result);
            return "";
        }
    }
    return result;    

}

void displayStrings(char* strs[], int size){
    for(int i = 0; i < size; i++){
        printf("%s\n", strs[i]);
    }
}


int main(){
    char* strs1[] = {"flower", "flow", "flight", "fly"}; //strs1[] can be considered a 2-D array
    //char* strs1[] is an array of char*, which means each char* points to a different string
    int size1 = sizeof(strs1)/sizeof(strs1[0]); //4 = 32/8, 1 char accounts for 8 bytes in 64-bit based systems.
    char* result;
    
    result = longestCommonPrefix(strs1, size1);
    
    displayStrings(strs1, size1);

    //printf("%d\n", size1); 
    //1 pointer in 64-bit is 8 byte. => 4 pointer equals to 32 bytes
    //printf("%ld\n", strlen(strs1[0])); 
    printf("%s\n", result);
}