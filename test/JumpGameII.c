#include <stdio.h>

int jump(int* nums, int numsSize) {
    int near = 0;
    int far = 0;
    int jumps = 0;

    while(far < numsSize - 1){
        int farthest = 0;
        for(int i = near; i < (far+1); i++){
            if(i + nums[i] > farthest){
                farthest = i + nums[i];
            }
        }

        near = far + 1;
        far = farthest;
        jumps += 1;
    }
    return jumps;
}


int main(){
    int nums[] = {2, 3, 1, 1, 4};
    int result = jump(nums, sizeof(nums) / 4);
    printf("%d\n", result);
}
