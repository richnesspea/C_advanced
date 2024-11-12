#include <stdio.h>

//Sử dụng Hashtable
//Không sử dụng với 
int majorityElement(int* nums, int numsSize) {
    int hash[10]={0};

    int res = 0;
    int majority = 0;

    for (int i = 0; i < numsSize; i++){
        hash[nums[i]] += 1;
        if(hash[nums[i]] > majority){
            res = nums[i];
            majority = hash[(nums[i])];
        }
    }
    return res;
}

//Moore-voting algorithm: https://www.youtube.com/watch?v=n5QY3x_GNDg 
//(Chỉ dùng được với mảng có tồn tại ít nhất 1 phần tử lớn hơn ít nhất 1 nửa số phần tử của mảng)
int majorityElement2(int* nums, int numsSize) {
    int count = 0;
    int candidate = -1;

    for (int i = 0; i < numsSize; i++) {
        if (count == 0) {
            candidate = nums[i];
            count = 1;
        } else if (nums[i] == candidate) {
            count++;
        } else {
            count--;
        }
    }
    return candidate;
}

int main(){
    int nums[] = {-1, -1, -1, 0, 0, 1, 1, 1, 2, 2, 2, 2, 3, 3, 4, -1, -1};
    int result = majorityElement2(nums, sizeof(nums)/4);
    printf("result = %d\n", result);
}