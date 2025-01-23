#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// For two strings s and t, we say "t divides s" if and only if s = t + t + t + ... + t + t (i.e., t is concatenated with itself one or more times).
// Given two strings str1 and str2, return the largest string x such that x divides both str1 and str2.


// Example 1:
// Input: str1 = "ABCABC", str2 = "ABC"
// Output: "ABC"

//Solution:
//Step 1:
    // First we check if str1 + str2 == str2 + str1
    // If it is equal than if find the longest common substring.
    // Otherwise we return "".

//Step 2:
    // Suppose str1 = "ABCABC" and str2 = "ABC"
    // str1 + str2 = ABCABCABC
    // str2 + str1 = ABCABCABC
    // str1 + str2 == str2 + str1
    // return str.substr(0, gcd(size(str1), gcd(size(str2))))
    // where gcd(3, 6) = 3
    // So, answer is "ABC"

    // Also str1 = "LEET", str2 = "CODE"
    // str1 + str2 = "LEETCODE"
    // str2 + str1 = "CODELEET"
    // So, return ""
int gcdInt(int a, int b){
    while(b != 0){
        int temp = a % b;
        a = b;
        b = temp;  
    }
    return a;
}

char* gcdOfStrings(char* str1, char* str2) {
    //Caculate the length of the string
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    //Concatenate strings to check for equivalence
    char concat1[len1 + len2 +1];
    char concat2[len1 + len2 +1];

    strcpy(concat1, str1);
    strcat(concat1, str2);

    strcpy(concat2, str2);
    strcat(concat2, str1);

    if(strcmp(concat1, concat2)){
        return "";
    }

    //Find the gcd of the lengths
    int gcdLength = gcdInt(len1, len2);

    //Allocate memory for the result
    //Solution 1: static allocation
    // static char result[1000];
    // strncpy(result, str1, gcdLength);
    // result[gcdLength]= '\0';
    //Solution 2: dynamic allocation
    char* result = (char*)malloc((gcdLength + 1) * sizeof(char));

    if(result == NULL){
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    

    strncpy(result, str1, gcdLength);
    result[gcdLength]= '\0';

    return result;
}

int main(){
    char str1[11] = "ABCABC";
    char str2[] = "ABC";

    //int result = gcdInt(32, 16);
    //printf("%d \n", result);

    // strcat(str1, str2);

    // printf("%ld\n", strlen(str1)); //the number of bytes that str1 consumes
    // printf("%ld\n", sizeof(str1)); //all the memory allocation for str1

    char* result = gcdOfStrings(str1, str2);
    printf("%s \n", result);

}