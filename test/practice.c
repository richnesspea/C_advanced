#include <stdio.h>

//removeElemenent: 1 lần

int removeElement(int* nums, int numsSize, int val) {
    int k = 0;
    for(int i = 0; i < numsSize; i++){
        if(nums[i] != val){
            nums[k] = nums[i];
            k++;
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
    int nums[] = {3, 5, 2, 3, 3, 1, 4};
    int result = removeElement(nums, sizeof(nums)/4, 3);
    printArray(nums, sizeof(nums)/4);
    printf("%d\n", result);

}