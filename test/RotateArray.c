#include <stdio.h>

// Example 1:

// Input: nums = [1,2,3,4,5,6,7], k = 3
// Output: [5,6,7,1,2,3,4]
// Explanation:
// rotate 1 steps to the right: [7,1,2,3,4,5,6]
// rotate 2 steps to the right: [6,7,1,2,3,4,5]
// rotate 3 steps to the right: [5,6,7,1,2,3,4]

//Solution 1: Using remainder
//  Step1: k = k % length of input array (k is the number of rotates that we need to make)
//  Step2: Caculate rotated positions
//          (current position + remainder) % length of input array
            // For 1(= index 0), (0 + 2) % 7 = 2
            // For 2(= index 1), (1 + 2) % 7 = 3
            // For 6(= index 5), (5 + 2) % 7 = 0
            // For 7(= index 6), (6 + 2) % 7 = 1

void rotate(int* nums, int numsSize, int k) {
    int arr[numsSize];

    k = k % numsSize;

    for(int i = 0; i < numsSize; i++){
        int newIndex = (i+k) % numsSize;
        arr[newIndex] = nums[i]; 
    }

    for(int i = 0; i < numsSize; i++){
        nums[i] = arr[i]; 
    }
}

void printArray(int *arr, int size){
    for(int i = 0; i < size; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}


int main(){
    int nums[] = {1, 2, 3, 4, 5 ,6, 7, 8, 9};
    rotate(nums, sizeof(nums)/4, 3);
    printArray(nums, sizeof(nums)/4);

}
