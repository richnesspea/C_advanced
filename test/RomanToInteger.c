#include <stdio.h>
#include <string.h>

// Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

// Symbol       Value
// I             1
// V             5
// X             10
// L             50
// C             100
// D             500
// M             1000
// For example, 2 is written as II in Roman numeral, just two ones added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

// Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

// I can be placed before V (5) and X (10) to make 4 and 9. 
// X can be placed before L (50) and C (100) to make 40 and 90. 
// C can be placed before D (500) and M (1000) to make 400 and 900.
// Given a roman numeral, convert it to an integer.

 // Example 1:
// Input: s = "III"
// Output: 3
// Explanation: III = 3.

// Example 2:
// Input: s = "LVIII"
// Output: 58
// Explanation: L = 50, V= 5, III = 3.

// Example 3:
// Input: s = "MCMXCIV"
// Output: 1994
// Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.


//Solution 1: 
    //If arr[i] > arr[i+1]: add
    //If arr[i] < arr[i+1]: substract
int romanToInt(char* s) {
    int result = 0;
    int length = strlen(s);
    //Loop through each character int he Roman numeral string
    for(int i = 0; i < length; i++){
        int value;
        switch(s[i]){
            case 'I': 
                value = 1;
                break;
            case 'V': 
                value = 5;
                break;
            case 'X': 
                value = 10;
                break;
            case 'L': 
                value = 50;
                break;
            case 'C': 
                value = 100;
                break;
            case 'D': 
                value = 500;
                break;
            case 'M': 
                value = 1000;
                break;
            default:
                value = 0;
        }
        //Check the s[i+1] is to check whether s[i] should be substracted or added
        if(i < (length -1)){
            int nextvalue;
            switch(s[i+1]){
                case 'I': 
                    nextvalue = 1;
                    break;
                case 'V': 
                    nextvalue = 5;
                    break;
                case 'X': 
                    nextvalue = 10;
                    break;
                case 'L': 
                    nextvalue = 50;
                    break;
                case 'C': 
                    nextvalue = 100;
                    break;
                case 'D': 
                    nextvalue = 500;
                    break;
                case 'M': 
                    nextvalue = 1000;
                    break;
                default:
                    nextvalue = 0;
            }   

            if(value < nextvalue){
                result -= value;
            }
            else{
                result += value;
            }           
        }
        else{
            result += value;
        }
    }
    return result;
}

int main(){
    char s1[] = "III";
    char s2[] = "LVIII";
    char s3[] = "MCMXCIV";

    printf("Roman numeral %s = %d\n", s1, romanToInt(s1));
    printf("Roman numeral %s = %d\n", s2, romanToInt(s2));
    printf("Roman numeral %s = %d\n", s3, romanToInt(s3));
}