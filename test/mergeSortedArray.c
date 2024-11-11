#include <stdio.h>
//https://www.youtube.com/watch?v=xli_FI7CuzA Tutorial for bubble sort
//https://www.youtube.com/watch?v=4VqmGXwpLqc&list=PL9xmBV_5YoZOZSbGAXAPIq1BeUf4j20pl Tutorial for some sorting algorithms

void bubbleSort(int *arr, int size){
    for(int i = 0; i < size - 1; i++){         //sau mỗi vòng lặp thì tại vị trí cao nhất sẽ được sắp xếp 
        for(int j = 0; j < size - i - 1; j++){ //Nên là j sẽ không cần lặp đến vị trí size - 1 - i nữa
            if(arr[j] > arr[j + 1]){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp; 
            }
        }
    }
}



//Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3

void merge(int* nums1,int m, int* nums2, int n) {
    int p1 = m - 1; //points to the last element of nums1: points to 3
    int p2 = n - 1; //points to the last element of nums2: points to 6
    int p = m + n - 1; //points to 0

    while (p1 >= 0 && p2 >= 0){
        if(nums1[p1] > nums2[p2]){ 
            nums1[p] = nums1[p1];
            p1--;
        }
        else{
            nums1[p] = nums2[p2];
            p2--;
        }
        p--;
    }

    while(p2 >= 0){
        nums1[p] = nums2[p2];
        p2--;
        p--;
    }
}

void printArray(int *arr, int size){
    for(int i = 0; i < size; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main(){
    int nums1[] = {}; 
    int m = 0;                        
    int nums2[] = {1};          
    int n = 1;                        

    merge(nums1, m, nums2, n);        // Gọi hàm merge

    printf("Mảng sau khi hợp nhất: ");
    printArray(nums1, m + n);         // In ra mảng đã hợp nhất
    return 0;
}