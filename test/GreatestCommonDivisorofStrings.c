#include <stdio.h>

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


char* gcdOfStrings(char* str1, char* str2) {
    
}

int main(){
    char str1[] = "ABCABC";
    char str2[] = "ABC";
}