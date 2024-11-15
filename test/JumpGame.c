#include <stdio.h>
#include <stdbool.h>
// You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.
// Return true if you can reach the last index, or false otherwise.

// Example 1:
// Input: nums = [2,3,1,1,4]
// Output: true
// Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.

// Example 2:
// Input: nums = [3,2,1,0,4]
// Output: false
// Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.

bool canJump(int *nums, int numsSize) {
    int maxReach = 0; // Tracks the farthest index we can reach

    for (int i = 0; i < numsSize; i++) {
        // If our current position is beyond the farthest reachable index, we can't proceed
        if (i > maxReach) {
            return false;
        }
        // Update the farthest reachable index
        if (i + nums[i] > maxReach) {
            maxReach = i + nums[i];
        }
        // If the farthest reachable index is beyond or at the last index, we can reach the end
        if (maxReach >= numsSize - 1) {
            return true;
        }
    }

    return false; // If we finish the loop without reaching the end
}


int main()
{
    int nums[] = {2,3,1,1,4};
    bool result = canJump(nums, sizeof(nums) / 4);
    if (result == true)
    {
        printf("true\n");
    }
    else
    {
        printf("false\n");
    }
}
