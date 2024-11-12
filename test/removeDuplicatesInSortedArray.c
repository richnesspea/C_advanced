#include <stdio.h>

//Sử dụng vòng lặp for để duyệt hết mảng với biến chạy i
//k là vị trí mà tại đó n[k] != n[k-1] (nghĩa là trước đó không bị lặp rồi)
//I và k xuất phát từ vị trí = 1, duyệt với điều kiện n[i] != n[k-1]
int removeDuplicates(int* nums, int numsSize) {
    int k = 1;
    int i = 1; 
    for(i = 1; i < numsSize; i++){
        if(nums[i] != nums[k-1]){
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
    int nums[] = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int result = removeDuplicates(nums, sizeof(nums)/4);
    printArray(nums, sizeof(nums)/4);
    printf("result = %d", result);

}