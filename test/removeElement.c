#include <stdio.h>
//Cho một vòng lặp for với biến chạy là i, với mỗi giá trị thỏa mãn arr[i] khác val thì sẽ lưu vào vị trí arr[k] và cho k + 1 đợi tiếp tục
int removeElement(int* nums, int numsSize, int val) {
    int k = 0;
    for(int i = 0; i < numsSize; i++){
        if(nums[i] != val){
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
    int nums[] = {3, 2, 1, 4};
    int k;
    k = removeElement(nums, 4, 3);
    printArray(nums, 4);
    printf("k = %d\n", k);
}