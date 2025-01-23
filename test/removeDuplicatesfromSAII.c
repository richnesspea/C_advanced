#include <stdio.h>

int nums[] = {0, 0, 0, 3, 3, 3, 4, 4, 5, 6, 7, 7, 7};


int removeDuplicatesII(int* nums, int numsSize) {
    int k = 2;
    int i;

    if (numsSize <= 2){
        return numsSize;
    }
    
    for(i = 2; i < numsSize; i++){
        if(nums[i] != nums[k-2]){
            nums[k] = nums[i];
            k += 1;
        }
    }
    return k;
}

void printArray(int *arr, int size){
    for(int i = 0; i < size; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}



int main(){
    
    int result = removeDuplicatesII(nums, sizeof(nums)/4);
    printArray(nums, sizeof(nums)/4);
    printf("result = %d", result);

}